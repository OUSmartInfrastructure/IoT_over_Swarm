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
To achieve the project objectives, the project was divided into 3 phases and finally merged to deliver the End-to-End Connectivity:
Project-A: Satellite Connectivity Setup
Project-B: WIFI-over-Serial Connectivity Setup
Project-C: Green-house Connectivity Setup
## Project-A: Satellite Connectivity Setup
* Purchase the Swarm M138 Kit
## Getting Started
To get things started, it was required to:
* Purchase the Swarm M138 Kit
* Setup the Swarm M138 Kit
  * Register the Swarm M138 Kit
  * Install Software
  * Transmit Messages over the Satellite network-Test Case
* Setup the Adafruit QT Py
  * Install Software
* Connecting the Adafruit QT Py to the Swarm M138 board
* * Writing a wifi-to-serial communication media
  * Test Communication with over Spacebee
  * Testing the Connectivity.
## Purchase the Swarm M138 Kit
The Swarm M138 package toolkit can be purchased online from:
[Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196)
## Setup the Swarm M138 Kit
### Hardware Components
The Swarm M138 kit consist of the following key components:
1. Swarm M138 Modem: This is the main communication modem used for transmitting and receiving data over the satellite network.
   __Figure 1:Front-view of M138 board__
   ![M138 board](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138.png)
2. SparkFun Satellite Transceiver Breakout: This beakout board facilitates communication with satellites, enabling date transmission and reception.
   __Figure 2:Back-view of M138 board__
   ![Transceiver Breakout](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/breakoutpins.png)
   [Transceiver Breakout Pins](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#breakout-pins)
3. Swarm VHF Antenna and SparkFun Ground Plane: These componets are essental for establishing VHF (Very High Frequency) communication, which may be used for specific satellite communication protocols or ground-based communication.
   __Figure 3:VHF-Antenna and Ground-Plane__
   ![VHF Transceiver & Groundplane](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/VHF%20Antenna%2BGroundplane.jpg)
4. Molex adhesive u.FL GNSS Antenna: This antenna is designed for GNSS (Global Navigation Satellite System) applications such as GPS, GLONASS, or Galileo to provide accurate positioning information.
   __Figure 4:M138 board and GNSS Antenna__
   ![GNSS Antenna](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/GNSS%20Antenna.jpg)
5. 2 x 25mm u.FL cables, u.FL to SMA adapter, and 2 x M2.5 screws: These accessories are used for connecting and seucuring the antennas and other components in the assembly.
### Hardware Connection
The initial hardware setup involves:
1. Connect the VHF port on the modem with a u.FL cable to the VHF Transceiver and ground-plane.
2. Connect the GPS port on the modem with a u.FL cable to the GNSS Antenna.
3. Connect the type-c port on the modem to the USB port on PC that delivers 3.0V to 5V (preferably 3.3V).
4. Ensure the M138 modem is in an open space free from moisture to enable it get its GPS logged onto the satellite.
The figure below provides an illustration of the setup in our lab environment:
 __Figure 5:Swarm-M138 Connection Setup in lab__
   ![Hardware connection](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Hardware%20connection%20setup.jpg)
### Register the Swarm M138 Kit
The newly purchased M138 board is registered to allow for a monthly subscription package of about $5 for a 750 data packet plan.
The following are the steps to register the modem:
1. Create a hive account and [sign-in](https://bumblebee.hive.swarm.space/hive/ui/sign-up). After signing up, a registration email will be sent to you.
2. Navigate to [register the device](https://bumblebee.hive.swarm.space/registerDevice).
3. Click on the start scanning button to scan your swarm M138 modem QR code as shown below:
    __Figure 6:M138 board online registration__
   ![Scan QR code](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Scanning%20Modem%20to%20register.png)
### M138 Modem GUI Software Setup
The modem comes with a written python user friendly interface which can be downloaded and installed on your PC as follows:
1. Download the SparkFun_Swarm_M138_GUI from [Python GUI](https://github.com/sparkfun/SparkFun_Swarm_M138_GUI/releases).
2. In this example, we will illustrate how to install the windows version (SwarmM138GUI.win.zip) as follows: Double click to install the application.
   __Figure 7:M138 board Local control software__
   ![SwarmM138 Win.version](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/SwarmM138GUI.win.exe.jpg).
4. After installation, you will be welcomed with a user interface as shown below: This software will be used to control the M138 board locally to send and receive messages via the USB Serial CH340 COM port.
    __Figure 8:M138 board Local control installed software__
   ![SwarmM138 GUI](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138_User_interface_GUI.png).
NB: Ensure your PC supports the [USB-SERIAL CH340 drivers](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers).
After, connect the type-c port on the modem to the USB port on PC and the PC should be able to detect it as shown above.
## Test Satellite communication media
Now that we have our setup, we will proceed to send our first message from the M138 board to SparkFun Satellite, which will in-turn transport the message to a ground Swarm Hive. We will then use a browser and make REST API calls from our PC to the Swarm Hive to download the messages. Note that the reverse is also true: We can send messages to the Swarm Hive to be delivered to our M138 board once the satellite hovers over our board and exchanges beacon frames with it.

### Send Message from Swarm M138 board
1. Connect the setup as shown in figure 5 and ensure the antenna is in the [clear view of the sky](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#overview-of-the-swarm-network). The [LED](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#hardware-hookup---usb) on the M138 board blinks green when it automatically locks its GPS to a satellite.
2. Open the SparkFun_Swarm_M138_GUI, select the correct COM port, and click on "Open Port" as shown in figure 8.
