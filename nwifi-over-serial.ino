#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

// Define WiFi credentials:
const char* ssid = "a-itswireless";       // Your WiFi SSID
const char* password = "1234567890";  // Your WiFi password

WebServer server(80);

String serialOutputToSwarm; // Variable to accumulate serial output to Swarm board
String serialOutputFromSwarm; // Variable to accumulate serial output from Swarm board
String receivedDataFromSwarm; // Variable to accumulate data received from Swarm board
int selectedBaudRate = 115200; // Default baud rate
int messageId = 0; // Unique ID for each message sent

struct MessageResponse {
  int id;
  String message;
};

std::vector<MessageResponse> messageResponses; // Store sent messages along with their IDs

void setup() {
  Serial.begin(115200);
  Serial1.begin(selectedBaudRate); // Begin with default baud rate

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start web server
  server.on("/", HTTP_GET, handleRoot);
  server.on("/serial", HTTP_POST, handleSerial); // Change HTTP method to POST
  server.on("/reset_received_data", HTTP_GET, [](){
    receivedDataFromSwarm = ""; // Clear the received data
    server.sendHeader("Location", "/");
    server.send(303);
  });
  server.on("/getSerialOutput", HTTP_GET, handleSerialOutput); // New route to get serial output
  server.begin();
  Serial.println("Web server started");

  // Wait for serial monitor to open
  while (!Serial);
  Serial.println("Serial communication initialized with Swarm board.");
}

void loop() {
  server.handleClient();

  // Check if data is available from Swarm board:
  if (Serial1.available() > 0) {
    String receivedData = Serial1.readStringUntil('\n');
    receivedData.trim();
    Serial.println("Received data from Swarm board: " + receivedData);
    serialOutputFromSwarm += "Received data from Swarm board: " + receivedData + "<br>";
    receivedDataFromSwarm += receivedData + "<br>"; // Append received data to third window

    // Match response with sent message
    for (int i = 0; i < messageResponses.size(); i++) {
      if (messageResponses[i].message == receivedData) {
        Serial.println("Matched response with ID " + String(messageResponses[i].id));
        // Do something with the matched response
        messageResponses.erase(messageResponses.begin() + i); // Remove matched message from vector
        break; // Exit loop after finding the match
      }
    }
  }

  // Check for data from ESP32 and send to Swarm board
  if (Serial.available() > 0) {
    String userInput = Serial.readStringUntil('\n');
    userInput.trim();
    Serial.println("Sending data to Swarm board: " + userInput);
    Serial1.println(userInput);  // Send user input to Swarm board
    serialOutputToSwarm += "From-WiFi: " + userInput + "<br>"; // Modified line

    // Store sent message with unique ID
    messageResponses.push_back({messageId, userInput});
    messageId++;
  }
}

void handleRoot() {
  // Get the IP address of the ESP32
  IPAddress ip = WiFi.localIP();

  String html = "<!DOCTYPE html><html><head><title>ESP32 Web Interface</title>";
  html += "<style>";
  html += "body {";
  html += "  font-family: Arial, sans-serif;";
  html += "  background-image: url('https://x2n.com/wp-content/uploads/2020/10/leo-satellite-constellation-1024x576.jpg');"; // Background image URL
  html += "  background-size: cover;";
  html += "  background-repeat: no-repeat;";
  html += "  background-attachment: fixed;";
  html += "}";
  html += "h1, h2 {";
  html += "  color: #333;";
  html += "  font-size: 24px;"; // Increase font size for headings
  html += "}";
  html += ".container {";
  html += "  max-width: 2000px;";
  html += "  margin: 0 auto;";
  html += "  padding: 20px;";
  html += "  background-color: #fff;";
  html += "  box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);";
  html += "}";
  html += ".serialOutput {";
  html += "  border: 1px solid #ccc;";
  html += "  padding: 10px;";
  html += "  margin-top: 10px;";
  html += "  background-color: #f9f9f9;";
  html += "  font-family: Consolas, monospace;";
  html += "  font-size: 22px;"; // Increase font size for serial output
  html += "  width: 2000px;"; // Fixed width
  html += "  height: 300px;"; // Fixed height
  html += "  overflow: auto;"; // Add scroll bars inside the window
  html += "}";
  html += ".serialOutputContainer {";
  html += "  display: flex;";
  html += "  align-items: center;";
  html += "}";
  html += ".resetButton {";
  html += "  margin-left: 10px;"; // Adjust margin as needed for spacing
  html += "}";
  html += "</style>";
  html += "</head><body>";

  html += "<div class='container'>";
  html += "<h1>WIFI-SERIAL-COMMUNICATION-INTERFACE</h1>";
  html += "<h2>Webserver-IPv4: " + ip.toString() + "</h2>";

  html += "<h2>Baud Rate Configuration</h2>";
  html += "<form action='/serial' method='post'>";
  html += "Baud Rate: <select name='baudRate'>";
  html += "<option value='115200'>115200</option>";
  html += "<option value='9600'>9600</option>";
  html += "<option value='57600'>57600</option>";
  // Add more baud rates as needed
  html += "</select><br>";
  html += "<input type='submit' value='Set Baud Rate'>";
  html += "</form>";

  html += "<h2>Send Data to Swarm Board</h2>";
  html += "<form action='/serial' method='post' class='sendForm'>";
  html += "Data to send: <input type='text' name='data' style='flex: 1; font-size: 24px;'>"; // Set input to take remaining space
  html += "<input type='submit' value='Send' style='margin-left: 10px;'>"; // Add margin-left for spacing
  html += "</form>";

  html += "<h2>Data Sent</h2>";
  html += "<div class='serialOutputContainer'>";
  html += "<div class='serialOutput serialOutputToSwarm' id='serialOutputToSwarm'>";
  html += serialOutputToSwarm;
  html += "</div>";
  html += "<div class='resetButton'>";
  html += "<button onclick='resetSerialOutput(\"serialOutputToSwarm\")'>Reset</button>"; // Reset button for serial output to Swarm
  html += "</div>";
  html += "</div>";

  html += "<h2>Data Received</h2>";
  html += "<div class='serialOutputContainer'>";
  html += "<div class='serialOutput serialOutputFromSwarm' id='serialOutputFromSwarm'>";
  html += serialOutputFromSwarm;
  html += "</div>";
  html += "<div class='resetButton'>";
  html += "<button onclick='resetSerialOutput(\"serialOutputFromSwarm\")'>Reset</button>"; // Reset button for serial output from Swarm
  html += "</div>";
  html += "</div>";

  html += "<h2>Operation Logs</h2>";
  html += "<div class='serialOutputContainer'>";
  html += "<div class='serialOutput' id='receivedDataFromSwarm'>";
  html += receivedDataFromSwarm;
  html += "</div>";
  html += "<div class='resetButton'>";
  html += "<button onclick='resetSerialOutput(\"receivedDataFromSwarm\")'>Reset</button>"; // Reset button for received data from Swarm
  html += "</div>";
  html += "</div>";

  // Add the reference manual table
  html += "<h2>Command Reference Manual</h2>";
  html += "<table>";
  html += "<tr><th>Command</th><th>Description</th><th>Example Command</th></tr>";
  html += "<tr><td>$CS</td><td>Configuration Settings</td><td>$CS*10</td></tr>";
  html += "<tr><td>$DT</td><td>Date/Time Status</td><td>$DT*</td></tr>";
  html += "<tr><td>$FV</td><td>Firmware Version Read</td><td>$FV*</td></tr>";
  html += "<tr><td>$GJ</td><td>GPS Jamming/Spoofing Indication</td><td>$GJ*23</td></tr>";
  html += "<tr><td>$GP</td><td>GPIO1 Control/Status</td><td>$GP*</td></tr>";
  html += "<tr><td>$MM</td><td>Messages Received Management (2-way operation)</td><td>$MM*</td></tr>";
  html += "<tr><td>$MT</td><td>Messages to Transmit Management</td><td>$MT*</td></tr>";
  html += "<tr><td>$PO</td><td>Power Off</td><td>$PO*</td></tr>";
  html += "<tr><td>$PW</td><td>Power Status</td><td>$PW*</td></tr>";
  html += "<tr><td>$RD</td><td>Receive Data Unsolicited Message</td><td>$RD*29</td></tr>";
  html += "<tr><td>$RS</td><td>Restart Device</td><td>$RS*</td></tr>";
  html += "<tr><td>$RT</td><td>Receive Test</td><td>$RT*</td></tr>";
  html += "<tr><td>$SL</td><td>Sleep Mode</td><td>$SL*</td></tr>";
  html += "<tr><td>$M138</td><td>Modem Status Unsolicited Message</td><td>$M138*</td></tr>";
  html += "<tr><td>$TD</td><td>Transmit Data</td><td>$TD*18</td></tr>";
  html += "</table>";

  html += "</div>"; // Close the container div

  html += "<script>";
  html += "function resetSerialOutput(elementId) {";
  html += "  var element = document.getElementById(elementId);";
  html += "  element.innerHTML = '';"; // Clear the content of the specified element
  html += "}";
  html += "function updateSerialOutput(elementId) {";
  html += "  var element = document.getElementById(elementId);";
  html += "  fetch('/getSerialOutput?id=' + elementId) // Fetch the latest serial output";
  html += "    .then(response => response.text())";
  html += "    .then(data => {";
  html += "      element.innerHTML = data;"; // Update the serial output div with the latest data
  html += "    });";
  html += "}";
  html += "setInterval(function() {";
  html += "  updateSerialOutput('serialOutputToSwarm');"; // Call updateSerialOutput function for 'serialOutputToSwarm'
  html += "  updateSerialOutput('serialOutputFromSwarm');"; // Call updateSerialOutput function for 'serialOutputFromSwarm'
  html += "}, 1000);"; // Update every 1 second
  html += "</script>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleSerial() {
  if (server.hasArg("data")) {
    String data = server.arg("data");
    Serial.println("From-WiFi: " + data);
    serialOutputToSwarm += "From-WiFi: " + data + "<br>";

    // Forward data to Swarm board
    Serial1.println(data);  // Send received data to Swarm board

    // Store sent message with unique ID
    messageResponses.push_back({messageId, data});
    messageId++;
  } else {
    Serial.println("No data received");
    serialOutputToSwarm += "No data received<br>";
  }

  // Check for selected baud rate
  if (server.hasArg("baudRate")) {
    selectedBaudRate = server.arg("baudRate").toInt();
    Serial.println("Selected Baud Rate: " + String(selectedBaudRate));
    Serial1.end(); // Close current serial connection
    delay(100); // Introduce a small delay before reopening serial connection
    Serial1.begin(selectedBaudRate); // Update the baud rate
  }

  // Redirect back to the root page to display updated content
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleSerialOutput() {
  String id = server.arg("id");
  if (id == "serialOutputToSwarm") {
    server.send(200, "text/plain", serialOutputToSwarm);
  } else if (id == "serialOutputFromSwarm") {
    server.send(200, "text/plain", serialOutputFromSwarm);
  } else {
    server.send(404, "text/plain", "Invalid serial output ID");
  }
}
