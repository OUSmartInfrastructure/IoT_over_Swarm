# IoT_over_Swarm
This project is for setting up a green-roof IoT device to communicate with a Swarm M138 board over spacebee satellite network.
The objectives of the project are to monitor and manage green spaces, promote environmental sustainability, and leverage on advanced IoT technologies.
### Project Objectives
* Promote Remote Monitoring: The project seeks to promote remote monitoring of green roofs in real-time;enabling constant observation and analysis of environmental conditions including temperature, humidity, moisture levels, light intensity, wind speed,  air quality, and biodivisty.
* Promote Environmental Sustainability: The project contributes to environmental sustaninability by promoting green spaces, reducing heat island effects in urban areas, and improving air quality.
* Encourage Low cost solutions: The Swarm M138 boards offer low-cost, low-power, and long-range communications over satellite in areas where traditional networks may be unavailable or unreliable thereby making it suitable reduced maintenance costs and improved environmental monitoring.
* Scalability: The project could be scaled to monitor multiple greeen roofs across different locations to provide valuable data for urban planning, environmental research, and sustainable development initiatives.
* Research and Innovation: The project fosters research and innovation in the fields of IoT, satellite communication, and environmental monitoring to the development of new technologies and solutions for sustainable urban development.
## Overview of Project Toolkits
* **Swarm M138 boards:**
The [Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196) satellite data modem was used to transmit and receive data over the spacebee satellite. This provided the desired non-terrestrial connectivity between our remote green-field site and our local site (NOC).
The Swarm M138 has an in-built GNSS receiver that makes it perfect for sending and receiving very short messages using the [NMEA command reference](https://www.sparkfun.com/datasheets/GPS/NMEA%20Reference%20Manual-Rev2.1-Dec07.pdf) language.
* **Adafruit QT Py ESP32:**
The [Adafruit QT Py ESP32](https://www.adafruit.com/product/5395#description) is a highly versatile development board that has been designed with great precision and attention to detail by Adafruit Industries.
It has a compact form, and is equipped with a range of built-in sensors and connectivity options that make it an ideal choice to be used to collect data including temperature, humidity, and air quality, from sensors and transmit them wirelessly to a base station for further processing, visualization, and analysis. In this project, the QT Py was configured as a WiFi-to-Serial platform to enable remote control of the Swarm board via a wireless network connection.
## Setup Topology
The network was setup as follows:
![Topology](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Network%20Topology%20updated2.png)

## Project Category
To meet the project objectives, the work was broken down into three distinct phases, each focusing on a specific aspect. These phases were later integrated to ensure comprehensive end-to-end connectivity:
* Phase-A: Satellite Connectivity Setup
* Phase-B: WIFI-over-Serial Connectivity Setup
* Phase-C: Green-house Connectivity Setup
### Project-A: Satellite Connectivity Setup
* The deployment of the satellite connectivity involved:
  * Procurement of Swarm M138 Board
  * Hardware Setup of Swarm M138 Board
  * Registration of Swarm board
  * Downloading supporting Python Program
  * Sending and Receiving messages over Satellite Network
  * Monitoring of Satellite Constellations
#### Procurement of Swarm M138 Board
The Swarm M138 package toolkit is available for purchase online at [Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196)
The kit comprises essential components for satellite communication:
1. Swarm M138 Modem: This is the primary communication modem for data transmission over the satellite network.
   * Front-view of M138 board
   __Figure 1:Front-view of M138 board__
   ![M138 board](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138.png)
2. SparkFun Satellite Transceiver Breakout: Facilitates communication with satellites for data transmission and reception.
   * Back-view of M138 board
   __Figure 2:Back-view of M138 board__
   ![Transceiver Breakout](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/breakoutpins.png)
   [Transceiver Breakout Pins](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#breakout-pins)
3. Swarm VHF Antenna and SparkFun Ground Plane: Essential for VHF communication, suitable for satellite protocols or ground-based communication.
   * VHF-Antenna and Ground-Plane
   __Figure 3:VHF-Antenna and Ground-Plane__
   ![VHF Transceiver & Groundplane](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/VHF%20Antenna%2BGroundplane.jpg)
4. Molex adhesive u.FL GNSS Antenna: Designed for GNSS applications like GPS, GLONASS, or Galileo for precise positioning.
   * M138 board and GNSS Antenna
   __Figure 4:M138 board and GNSS Antenna__
   ![GNSS Antenna](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/GNSS%20Antenna.jpg)
5. Accessories:Includes 2 x 25mm u.FL cables, u.FL to SMA adapter, and 2 x M2.5 screws for connecting and securing antennas and components in the assembly.
#### Hardware Setup of Swarm M138 Board
To set up the Swarm M138 Board hardware effectively, the following were done:
1. Connected the VHF port on the modem to the VHF Transceiver and ground-plane using a u.FL cable.
2. Linked the GPS port on the modem to the GNSS Antenna with a u.FL cable.
3. Connected the type-C port on the modem to a PC's USB port providing 3.0V to 5V (ideally 3.3V).
4. Placed the M138 modem in a dry, open space to establish GPS connectivity with the satellite. For a visual representation of the setup in our lab environment, refer to:
   * Swarm-M138 Connection Setup in lab
 __Figure 5:Swarm-M138 Connection Setup in lab__
   ![Hardware connection](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/hardware%20setup.png)
#### Registration of Swarm board
To activate the newly acquired M138 board and subscribe to a $5 monthly package for a 750 data packet plan, the following are the steps to register the modem:
1. Begun by creating a hive account and signing in at [sign-in](https://bumblebee.hive.swarm.space/hive/ui/sign-up). Upon successful sign-up, an email for registration will be dispatched.
2. Proceeded to the device registration page by visiting [register the device](https://bumblebee.hive.swarm.space/registerDevice).
3. Initiated the registration process by clicking on the "start scanning" button to scan the QR code on the Swarm M138 modem. Refer to the illustration below for guidance:
   * M138 board online registration
    __Figure 6:M138 board online registration__
   ![Scan QR code](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Scanning%20Modem%20to%20register.png)
#### Downloading supporting Python Program
The modem is accompanied by a user-friendly Python interface that can be obtained and set up on a PC through the following steps:
1. The SparkFun_Swarm_M138_GUI can be downloaded from [Python GUI](https://github.com/sparkfun/SparkFun_Swarm_M138_GUI/releases).
2. For the Windows version installation (SwarmM138GUI.win.zip), the application can be installed by double-clicking on it.
   * The installation process is depicted below:
   __Figure 7:M138 board Local control software__
   ![SwarmM138 Win.version](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/SwarmM138GUI.win.exe.jpg).
3. Upon successful installation, a user interface will be displayed, enabling local control of the M138 board for message transmission and reception via the USB Serial CH340 COM port.
   * The installed software interface is shown below:
    __Figure 8:M138 board Local control installed software__
   ![SwarmM138 GUI](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138_User_interface_GUI.png).
NB: It is essential to verify that the PC supports the [USB-SERIAL CH340 drivers](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers).
Subsequently, connect the type-C port on the modem to the PC's USB port for detection, as illustrated above.
#### Sending and Receiving messages over Satellite Network
With the setup in place, the next step involved initiating the transmission of the first message from the M138 board to the SparkFun Satellite. Subsequently, the satellite relayed the message to a ground Swarm Hive. Following this, we utilized a web browser [Swarm-Hive](https://bumblebee.hive.swarm.space/messages/) to retrieve the messages stored in the Swarm Hive. It is important to note that the process works bidirectionally: messages can also be sent to the Swarm Hive for delivery to our M138 board once the satellite aligns over our board and establishes communication through beacon frames.
##### Send Message from Swarm M138 board
1. The setup was connected as illustrated in figure 5, ensuring that the antenna had a [clear view of the sky](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#overview-of-the-swarm-network).
2. The [LED](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#hardware-hookup---usb) on the M138 board blinked green upon automatically locking its GPS to a satellite.
3. The SparkFun_Swarm_M138_GUI was launched, the appropriate COM port was selected, and "Open Port" was clicked following the instructions provided in figure 8.
4. The desired message was input into the message dialogue box or chosen from preconfigured messages on the GUI to send.
5. The messages could include text, data, or [commands](https://cdn.sparkfun.com/assets/9/1/0/e/3/SwarmM138-Modem-Product-Manual.pdf), or any other supported communication format by the Swarm M138 module.
6. Once the message was composed, the GUI interface was used to send the message.
7. The GUI managed the communication protocol and data transmission to ensure successful delivery to the Swarm network.
8. The GUI provided feedback on the status of the message transmission, including delivery confirmation or encountered errors.
9. As an example, a message "Hello World!" was sent to the satellite, as depicted in the diagram below.
![Message-Sent](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Send%20Message.jpg)
##### Receive Message from Swarm M138 board
To receive messages from Swarm-M138 network, log into the [Swarm-Hive](https://bumblebee.hive.swarm.space/messages).
Note that messages sent to the Swarm Satellite may take up to 24 hours to deliver, depending on the satellite constellatio.
Users can also send messages, commands, or make REST API queries from the Swarm-Hive to control the Swarm-M138 board through the Swarm Satellite network.
 As an example, a message "Hello World!" was received from the satellite, as depicted in the diagram below.

 ![Message-Received](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Received%20Messages.jpg)

#### Monitoring of Satellite Constellations
To monitor the Satellite Constellation in Swarm Networks, the following tools were utilized:
1. **Swarm Pass Checker:** Swarm Networks offers a dedicated tool called [Swarm Pass Checker](https://kube.tools.swarm.space/pass-checker/).
                       This tool allows users to check for Swarm satellite passes over specific locations and times, enabling efficient monitoring and coordination of satellite communication.
2. **Heavens-Above:** [Heavens-Above](https://www.heavens-above.com/) is a popular platform used for tracking satellites and celestial objects.
                       It provides real-time information on satellite passes, including visibility predictions and orbital data, enhancing the ability to monitor and track Swarm satellite constellations.
3. **N2YO:** [N2YO](https://www.n2yo.com/database/?name=spacebee) is another valuable resource for tracking satellite locations and constellations.
                       Users can access detailed databases of satellites, including Swarm satellites like SpaceBEEs, to monitor their positions, trajectories, and visibility from specific locations on Earth.
   ![N2YO SPACEBEE TRACKING](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/n2yo%20satellite%20tracker.jpg)
   
We monitored the locations, movements, and constellations of the spacebee satellites, ensuring optimal communication and coordination within the satellite network.
   
### Project-B: WIFI-over-Serial Connectivity Setup
The significance of Project-B lied in allowing for a seamless connectivity and interaction with the Swarm M138 board without the need for physical cables or direct connections.
By establishing a WIFI-over-Serial connection using the Adafruit QT Py ESP32,we were able to exchange information, commands, and data wirelessly.
This setup enhanced flexibility, mobility, and convenience in deploying and managing the Swarm-M138 board. In addition, it facilitated the remote monitoring, control, and configuration of the Swarm board from the Adafruit and vice versa.
This capability is particularly valuable in scenarios where physical access to the devices is limited or impractical.
* The deployment of the WIFI-over-Serial connectivity involved:
  * Procurement of the Adafruit QT Py ESP32
  * Connectivity between the Swarm M138 Board and the QT-PY
  * Writing the C++ CODE to control the Swarm board via the QT-PY
  * Testing the Connectivity
#### Procurement of the Adafruit QT Py ESP32
The Adafruit QT Py ESP32 was purchased online from [Adafruit QT Py ESP32](https://www.adafruit.com/product/5395#description).
![QT PY](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Adafruit%20ESP32%20QT%20Py.jpg)
#### Connectivity between the Swarm M138 Board and the QT-PY
Before connecting the Swarm board to the QT Py, there was a requirement to open the jumper links on the back of the Swarm board [jumper links](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide/all#hardware-hookup---breakout-pins). The image below illustrates the location of these jumper links:

![Jumper links](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/21218-Swarm-BreakoutPinJumpers.jpg)

The TX0 breakout pin is connected to CH340 RX1 and the RXI is connected to CH340TX0. Both needs to be separated.
Subsequently, the following connections were made:
* GND was connected to GND / 0V on the QT-PY.
* VIN was connected to 3.3V on the QT-PY.
* TXO was connected to the Serial / UART RX input on the QT-PY.
* RXI was connected to the Serial / UART TX output on the QT-PY
  
**NB: Kindly consult the Network Topology for the diagrammatic setup.**

#### Writing the C++ CODE to control the Swarm board via the ESP32 QT-PY
The code provided is written in C++ for the [Arduino platform](https://www.arduino.cc/en/software). It utilizes libraries specific to Arduino, such as [**WiFi.h**](https://github.com/arduino-libraries/WiFi) and [**WebServer.h**](https://github.com/zhouhan0126/WebServer-esp32/tree/master), which are used for handling Wi-Fi connections and creating a web server, respectively.
The code is intended to run on an ESP32 microcontroller, which is commonly programmed using the Arduino IDE and the Arduino programming language (based on C++).
The full code we wrote can be found at ![wifi-over-serial](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/nwifi-over-serial.ino)
A detailed step-by-step explanation for the code is given as follows:

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

**1. // Define WiFi credentials:******
const char* ssid = "a-itswireless";       // Your WiFi SSID
const char* password = "123490";  // Your WiFi password
2. // Create Webserver:
WebServer server(80);  // Create a WebServer object listening on port 80

String serialOutputToSwarm; // Variable to accumulate serial output to Swarm board
String serialOutputFromSwarm; // Variable to accumulate serial output from Swarm board
String receivedDataFromSwarm; // Variable to accumulate data received from Swarm board
int selectedBaudRate = 115200; // Default baud rate

void setup() {
  Serial.begin(115200); // Initialize serial communication with baud rate 115200
  Serial1.begin(selectedBaudRate); // Begin serial communication with Swarm board using default baud rate

3.   // Connect to Wi-Fi
  WiFi.begin(ssid, password); // Connect to the specified WiFi network
  while (WiFi.status() != WL_CONNECTED) { // Wait until connected to WiFi
    delay(1000); // Wait for 1 second
    Serial.println("Connecting to WiFi..."); // Print connection status
  }
  Serial.println("Connected to WiFi"); // Print when successfully connected to WiFi

4.   // Start web server
  server.on("/", HTTP_GET, handleRoot); // Handle GET requests to root path ("/") with handleRoot function
  server.on("/serial", HTTP_POST, handleSerial); // Handle POST requests to "/serial" path with handleSerial function
  server.on("/reset_received_data", HTTP_GET, [](){ // Handle GET requests to "/reset_received_data" path with lambda function to reset received data
    receivedDataFromSwarm = ""; // Clear the received data
    server.sendHeader("Location", "/"); // Redirect back to the root page
    server.send(303); // Send HTTP response status 303 (See Other)
  });
  server.begin(); // Start the web server
  Serial.println("Web server started"); // Print message indicating web server started

5.   // Wait for serial monitor to open:
  while (!Serial); // Wait until Serial monitor is open
  Serial.println("Serial communication initialized with Swarm board."); // Print message indicating successful serial communication initialization
}

void loop() {
  server.handleClient(); // Handle incoming client requests

6.   // Check if data is available from Swarm board:
  if (Serial1.available() > 0) { // If data is available to read from Swarm board
    String receivedData = Serial1.readStringUntil('\n'); // Read data until newline character
    receivedData.trim(); // Remove leading and trailing whitespace
    Serial.println("Received data from Swarm board: " + receivedData); // Print received data
    serialOutputFromSwarm += "Received data from Swarm board: " + receivedData + "<br>"; // Accumulate received data with HTML line break
    receivedDataFromSwarm += receivedData + "<br>"; // Append received data to third window with HTML line break
  }

7.   // Check for data from ESP32 and send to Swarm board:
  if (Serial.available() > 0) { // If data is available to read from ESP32
    String userInput = Serial.readStringUntil('\n'); // Read data until newline character
    userInput.trim(); // Remove leading and trailing whitespace
    Serial.println("Sending data to Swarm board: " + userInput); // Print data being sent to Swarm board
    Serial1.println(userInput);  // Send user input to Swarm board
    serialOutputToSwarm += "Sending data to Swarm board: " + userInput + "<br>"; // Accumulate data being sent with HTML line break
  }
}

void handleRoot() {
8.   // Get the IP address of the ESP32
  IPAddress ip = WiFi.localIP(); // Get local IP address of the ESP32

9.   // Generate HTML content for the web page
  String html = "<!DOCTYPE html><html><head><title>ESP32 Web Interface</title>";
  html += "<style>";
  // CSS styles for the web page
  html += "body {";
  html += "  font-family: Arial, sans-serif;";
  html += "  background-image: url('https://x2n.com/wp-content/uploads/2020/10/leo-satellite-constellation-1024x576.jpg');"; // Background image URL
  html += "  background-size: cover;";
  html += "  background-repeat: no-repeat;";
  html += "  background-attachment: fixed;";
  html += "}";
10.   // CSS styles for various elements
  html += "h1, h2 {";
  html += "  color: #333;";
  html += "}";
  html += ".container {";
  html += "  max-width: 800px;";
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
  html += "}";
  html += ".serialOutputFromSwarm {";
  html += "  background-color: #ffffd5;";
  html += "}";
  html += ".serialOutputToSwarm {";
  html += "  background-color: #d7d9d7;";
  html += "}";
  html += "table {";
  html += "  width: 100%;";
  html += "  border-collapse: collapse;";
  html += "}";
  html += "th, td {";
  html += "  padding: 8px;";
  html += "  text-align: left;";
  html += "  border-bottom: 1px solid #ddd;";
  html += "}";
  html += "th {";
  html += "  background-color: #333;";
  html += "  color: #fff;";
  html += "}";
  html += "</style>";
  html += "</head><body>";

  html += "<div class='container'>";
  html += "<h1>WIFI-SERIAL-COMMUNICATION-INTERFACE</h1>";
  html += "<h2>Webserver-IPv4: " + ip.toString() + "</h2>";

  html += "<h2>Send Data to Swarm Board</h2>";
11.   // Form for sending data to Swarm board
  html += "<form action='/serial' method='post'>";
  html += "Data to send: <input type='text' name='data'><br>";
  html += "Baud Rate: <select name='baudRate'>";
  html += "<option value='115200'>115200</option>";
  html += "<option value='9600'>9600</option>";
  html += "<option value='57600'>57600</option>";
12.   // Add more baud rates as needed
  html += "</select><br>";
  html += "<input type='submit' value='Send'>";
  html += "</form>";

  html += "<h2>Data Sent</h2>";
13.   // Serial output window for data sent to Swarm board
  html += "<div class='serialOutput serialOutputToSwarm' id='serialOutputToSwarm'>";
  html += serialOutputToSwarm;
  html += "</div>";
14.   // Button to reset serial output window for data sent to Swarm board
  html += "<button onclick=\"resetSerialOutput('serialOutputToSwarm')\">Reset</button>";

  html += "<h2>Data Received</h2>";
15.  // Serial output window for data received from Swarm board
  html += "<div class='serialOutput serialOutputFromSwarm' id='serialOutputFromSwarm'>";
  html += serialOutputFromSwarm;
  html += "</div>";
16.   // Button to reset serial output window for data received from Swarm board
  html += "<button onclick=\"resetSerialOutput('serialOutputFromSwarm')\">Reset</button>";

  html += "<h2>Operation Logs</h2>";
17.   // Serial output window for operation logs
  html += "<div class='serialOutput' id='receivedDataFromSwarm'>";
  html += receivedDataFromSwarm;
  html += "</div>";
18.  // Button to reset serial output window for operation logs
  html += "<button onclick=\"resetSerialOutput('receivedDataFromSwarm')\">Reset</button>";

19.  // Add the reference manual table
  html += "<h2>Command Reference Manual</h2>";
  html += "<table>";
  html += "<tr><th>Command</th><th>Description</th><th>Example Command</th></tr>";
20.   // Table entries for command reference manual
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

21.   // JavaScript to automatically scroll serial output windows to bottom
  html += "<script>";
  html += "function scrollToBottom(elementId) {";
  html += "  var element = document.getElementById(elementId);";
  html += "  element.scrollTop = element.scrollHeight;";
  html += "}";
  html += "setInterval(function() {";
  html += "  scrollToBottom('serialOutputToSwarm');";
  html += "  scrollToBottom('serialOutputFromSwarm');";
  html += "  scrollToBottom('receivedDataFromSwarm');";
  html += "}, 1000);"; // Scroll every 1 second
22.   // JavaScript function to reset serial output window
  html += "function resetSerialOutput(elementId) {";
  html += "  var element = document.getElementById(elementId);";
  html += "  element.innerHTML = '';"; // Clear the content of the specified element
  html += "}";
  html += "</script>"; // Close script tag

  html += "</body></html>"; // Close HTML document

  server.send(200, "text/html", html); // Send HTML response with status code 200 (OK)
}

void handleSerial() {
  if (server.hasArg("data")) { // If data is received from the client
    String data = server.arg("data"); // Get the received data
    Serial.println("Received data from WiFi: " + data); // Print received data
    serialOutputToSwarm += "Received data from WiFi: " + data + "<br>"; // Accumulate received data with HTML line break

23.    // Forward data to Swarm board
    Serial.println("Forwarding data to Swarm board: " + data); // Print forwarded data
    Serial1.println(data);  // Send user input to Swarm board
    serialOutputToSwarm += "Forwarding data to Swarm board: " + data + "<br>"; // Accumulate forwarded data with HTML line break

 24.   // Wait for response from Swarm board
    delay(100); // Introduce a small delay for the response to be available
    while (Serial1.available() > 0) { // If response is available from Swarm board
      String response = Serial1.readStringUntil('\n'); // Read response until newline character
      response.trim(); // Remove leading and trailing whitespace
      Serial.println("Received response from Swarm board: " + response); // Print received response
      serialOutputFromSwarm += "Received response from Swarm board: " + response + "<br>"; // Accumulate received response with HTML line break
    }
  } else {
    Serial.println("No data received"); // Print message indicating no data received
    serialOutputToSwarm += "No data received<br>"; // Accumulate message indicating no data received with HTML line break
  }

25.  // Check for selected baud rate
  if (server.hasArg("baudRate")) { // If baud rate is specified by the client
    selectedBaudRate = server.arg("baudRate").toInt(); // Get the selected baud rate
    Serial.println("Selected Baud Rate: " + String(selectedBaudRate)); // Print selected baud rate
    Serial1.end(); // Close current serial connection
    delay(100); // Introduce a small delay before reopening serial connection
    Serial1.begin(selectedBaudRate); // Update the baud rate
  }

26.  // Redirect back to the root page to display updated content
  server.sendHeader("Location", "/"); // Set the redirection header to root page
  server.send(303); // Send HTTP response status 303 (See Other)
}
