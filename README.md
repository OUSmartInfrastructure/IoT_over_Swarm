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
* The deployment of the satellite connectivity involved involved:
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
   ![Hardware connection](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Hardware%20connection%20setup.jpg)
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
