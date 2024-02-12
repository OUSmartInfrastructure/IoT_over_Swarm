# IoT_over_Swarm
This project is for setting up a green-roof IoT device to communicate using the Swarm M138 boards over satellite network.
The objectives of the project are to monitor and manage green spaces, promote environmental sustainability, and leverage advanced technologies for positive social and ecological impacts.
## Project Objectives
* Promote Remote Monitoring: The project seeks to promote remote monitoring of green roofs in real-time;enabling constant observation and analysis of environmental conditions including temperature, humidity, moisture levels, light intensity, wind speed,  air quality, and biodivisty.
* Promote Environmental Sustainability: The project contributes to environmental sustaninability by promoting green spaces, reducing heat island effects in urban areas, and improving air quality.
* Encourage Low cost solutions: The Swarm M138 boards offer low-cost, low-power, and long-range communications over satellite in areas where traditional networks may be unavailable or unreliable thereby making it suitable reduced maintenance costs and improved environmental monitoring.
* Scalability: The project could be scaled to monitor mulitple greeen roofs across different locations to provide valuable data for urban planning, environmental research, and sustainable development initiatives.
* Research and Innovation: The project fosters research and innovation in the fields of IoT, satellite communication, and environmental monitoring to the development of new technologies and solutions for sustainable urban development.
## Overview of Project Toolkits
* **Swarm M138 boards**
The Swarm M138 satellite data modem transmits and receives data to and from Swarm’s space network and is designed to be embedded into any third-party product. 
The Swarm M138 allowsone to send and receive short messages, is perfect for a variety of low bandwidth use cases, and has a built-in GNSS receiver that makes it perfect for many tracking applications.
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
  * Software
* Test Satellite communication media
* Setup the Adafruit QT Py
* * Hardware
  * Software
* Connecting the Adafruit QT Py to the Swarm M138 board
## Purchase the Swarm M138 Kit
The Swarm M138 package toolkit can be purchased online from:
[Swarm M138](https://www.sparkfun.com/products/21287?_gl=1*1bzkibh*_ga*NDQ4NTc5Mzc2LjE3MDI5MzgxOTY.*_ga_T369JS7J9N*MTcwNzcxMjIzNS4yMi4wLjE3MDc3MTIyMzUuNjAuMC4w&_ga=2.204509072.142982747.1707712239-448579376.1702938196)
## Setup the Swarm M138 Kit
### Hardware
The Swarm M138 kit consist of the following key components:
1. Swarm M138 Modem: This is the main communication modem used for transmitting and receiving data over the satellite network.
   ![M138 board](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/M138.png)
3. SparkFun Satellite Transceiver Breakout: This beakout board facilitates communication with satellites, enabling date transmission and reception.
   ![Transceiver Breakou](https://github.com/OUSmartInfrastructure/IoT_over_Swarm/blob/main/breakoutpins.png)
5. Swarm VHF Antenna and SparkFun Ground Plane: These componets are essental for establishing VHF (Very High Frequency) communication, which may be used for specific satellite communication protocols or ground-based communication.
6. Molex adhesive u.FL GNSS Antenna: This antenna is designed for GNSS (Global Navigation Satellite System) applications such as GPS, GLONASS, or Galileo to provide accurate positioning information.
7. 2 x 25mm u.FL cables, u.FL to SMA adapter, and 2 x M2.5 screws: These accessories are used for connecting and seucuring the antennas and other components in the assembly.
### Register the Swarm M138 Kit
