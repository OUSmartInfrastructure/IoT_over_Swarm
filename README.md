# IoT_over_Swarm
This project is for setting up a green-roof IoT device to communicate using the Swarm M138 boards over satellite network.
The objectives of the project are to monitor and manage green spaces, promote environmental sustainability, and leverage advanced technologies for positive social and ecological impacts.
### Project Objectives
* Promote Remote Monitoring: The project seeks to promote remote monitoring of green roofs in real-time;enabling constant observation and analysis of environmental conditions including temperature, humidity, moisture levels, light intensity, wind speed,  air quality, and biodivisty.
* Promote Environmental Sustainability: The project contributes to environmental sustaninability by promoting green spaces, reducing heat island effects in urban areas, and improving air quality.
* Encourage Low cost solutions: The Swarm M138 boards offer low-cost, low-power, and long-range communications over satellite in areas where traditional networks may be unavailable or unreliable thereby making it suitable reduced maintenance costs and improved environmental monitoring.
* Scalability: The project could be scaled to monitor mulitple greeen roofs across different locations to provide valuable data for urban planning, environmental research, and sustainable development initiatives.
* Research and Innovation: The project fosters research and innovation in the fields of IoT, satellite communication, and environmental monitoring to the development of new technologies and solutions for sustainable urban development.
## Overview of Project Toolkits
* **Swarm M138 boards**
The Swarm M138 satellite data modem transmits and receives data to and from Swarm’s space network and is designed to be embedded into any third-party product. 
The Swarm M138 allow someone to send and receive short messages, is perfect for a variety of low bandwidth use cases, and has a built-in GNSS receiver that makes it perfect for many tracking applications.
It can be connected to a laptop using the serial-to-usb CH340 bus or to any IoT devices such as Raspberry Pi AND Adafruit to be used to send and receive messages anywhere.
The Swarm M138 package toolkit is shown below:
[Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196)
* **Adafruit QT Py ESP32**
The Adafruit QT Py ESP32 is a highly versatile development board that has been designed with great precision and attention to detail by Adafruit Industries.
It has a compact form, and is equipped with a range of built-in sensors and connectivity options that make it an ideal choice to be used to collect data including temperature, humidity, and air quality, from sensors and transmit them wirelessly to a base station for further processing, visualization, and analysis.
The Adafruit QT Py ESP32 is shown below:
[Adafruit QT Py ESP32](https://www.adafruit.com/product/5395#description)
## Getting Started
To get things started, it was required to:
* Purchase the Swarm M138 Kit
* Setup the Swarm M138 Kit
* * Hardware
  * Register the Swarm M138 Kit
  * Communication Software
* Test Satellite communication media
* Setup the Adafruit QT Py
* * Hardware
  * Software
* Connecting the Adafruit QT Py to the Swarm M138 board
## Purchase the Swarm M138 Kit
The Swarm M138 package toolkit can be purchased online from:
[Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196)
## Setup the Swarm M138 Kit
### Hardware Components
The Swarm M138 kit consist of the following key components:
1. Swarm M138 Modem: This is the main communication modem used for transmitting and receiving data over the satellite network.
   ![M138 board](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138.png)
2. SparkFun Satellite Transceiver Breakout: This beakout board facilitates communication with satellites, enabling date transmission and reception.
   ![Transceiver Breakout](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/breakoutpins.png)
   [Transceiver Breakout Pins](https://learn.sparkfun.com/tutorials/sparkfun-satellite-transceiver-kit---swarm-m138-hookup-guide#breakout-pins)
3. Swarm VHF Antenna and SparkFun Ground Plane: These componets are essental for establishing VHF (Very High Frequency) communication, which may be used for specific satellite communication protocols or ground-based communication.
   ![VHF Transceiver & Groundplane](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/VHF%20Antenna%2BGroundplane.jpg)
4. Molex adhesive u.FL GNSS Antenna: This antenna is designed for GNSS (Global Navigation Satellite System) applications such as GPS, GLONASS, or Galileo to provide accurate positioning information.
   ![GNSS Antenna](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/GNSS%20Antenna.jpg)
5. 2 x 25mm u.FL cables, u.FL to SMA adapter, and 2 x M2.5 screws: These accessories are used for connecting and seucuring the antennas and other components in the assembly.
### Hardware Connection
The initial hardware setup involves:
1. Connect the VHF port on the modem with a u.FL cable to the VHF Transceiver and ground-plane.
2. Connect the GPS port on the modem with a u.FL cable to the GNSS Antenna.
3. Connect the type-c port on the modem to the USB port on PC that delivers 3.0V to 5V (preferably 3.3V).
4. Ensure the M138 modem is in an open space free from moisture to enable it get its GPS logged onto the satellite.
The figure below provides an illustration of the setup in our lab environment:
   ![Hardware connection](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Hardware%20connection%20setup.jpg)
### Register the Swarm M138 Kit
The newly purchased M138 board is registered to allow for a monthly subscription package of about $5 for a 750 data packet plan.
The following are the steps to register the modem:
1. Create a hive account and [sign-in](https://bumblebee.hive.swarm.space/hive/ui/sign-up). After signing up, a registration email will be sent to you.
2. Navigate to [register the device](https://bumblebee.hive.swarm.space/registerDevice).
3. Click on the start scanning button to scan your swarm M138 modem QR code as shown below:
   ![Scan QR code](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/Scanning%20Modem%20to%20register.png)
### M138 Modem Communication Software
The modem comes with a written python user friendly interface which can be downloaded and installed on your PC as follows:
1. Download the SparkFun_Swarm_M138_GUI from [Python GUI](https://github.com/sparkfun/SparkFun_Swarm_M138_GUI/releases).
2. In this example, we will illustrate how to install the windows version (SwarmM138GUI.win.zip) as follows: Double click to install the application.
   ![SwarmM138 Win.version](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/SwarmM138GUI.win.exe.jpg).
3. After installation, you will be welcomed with a user interface as shown below:
   ![SwarmM138 GUI](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138_User_interface_GUI.png).
NB: Ensure your PC supports the [USB-SERIAL CH340 drivers](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers).
After, connect the type-c port on the modem to the USB port on PC and the PC should be able to detect it as shown above:
