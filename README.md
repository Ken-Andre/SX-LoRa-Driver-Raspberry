# SX1278 Driver on Raspberry Pi (ARM64)

## Overview

This repository contains the driver for the SX1278 LoRa module, specifically set up for Raspberry Pi running on an ARM64 architecture (e.g., Raspberry Pi 4 Model B). The driver allows for the initialization, configuration, sending, and receiving of data via the SX1278 LoRa module using Python.

## Prerequisites

Before you begin, ensure you have the following prerequisites installed on your Raspberry Pi:

1. **Raspberry Pi OS (64-bit)**
2. **Python 3.11**
3. **WiringPi library**

## Hardware Connections

Connect your SX1278 module to the Raspberry Pi GPIO pins as follows:

| SX1278 Pin | Raspberry Pi Pin | GPIO Number |
|------------|------------------|-------------|
| 3.3V       | Pin 1 (3V3)      | -           |
| GND        | Pin 6 (GND)      | -           |
| MISO       | Pin 21           | GPIO 9      |
| MOSI       | Pin 19           | GPIO 10     |
| SCK        | Pin 23           | GPIO 11     |
| NSS        | Pin 22           | GPIO 25     |
| RESET      | Pin 11           | GPIO 17     |
| DIO0       | Pin 7            | GPIO 4      |

## Software Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/SX1278-driver.git
   cd SX1278-driver
2. **Install dependencies:**
   Ensure you have the necessary libraries installed:
   ```bash
   sudo apt-get update
   sudo apt-get install python3.11 python3.11-dev gcc make wiringpi
3. **Build the driver:**
   Compile the driver with the following commands:
   ```bash
   make clean
   make lib
## Usage

### Python Interface

The driver provides a Python interface to interact with the SX1278 module.

1. **Initialize the module:**
   ```python
   import loralib

   mode = 1  # Operation mode
   frequency = 868000000  # Frequency in Hz
   spreading_factor = 7  # Spreading factor

   loralib.init(mode, frequency, spreading_factor)
2. **Send data:**
   ```python
   data = "Hello, LoRa!"
   loralib.send(data)
3. **Receive data:**
   ```python
   received_data = loralib.recv()
   if received_data:
       print(f"Received: {received_data}")
   else:
       print("No data received.")
## Example Script

Below is an example Python script demonstrating how to use the driver:

```python
import loralib

  # Initialize the module
mode = 1
frequency = 868000000
spreading_factor = 7
loralib.init(mode, frequency, spreading_factor)

# Send data
data = "Hello, LoRa!"
loralib.send(data)
print("Data sent.")

# Attempt to receive data
received_data = loralib.recv()
if received_data:
    print(f"Received: {received_data}")
else:
    print("No data received.")
```
## Troubleshooting

- Ensure all hardware connections are secure and correct.
- Verify that the WiringPi library is correctly installed.
- Check that the SX1278 module is powered and functioning.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue to improve the driver.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgments

This driver is based on initial work by DORJI.COM and the SX1278_LoRa project. See [SX1278_LoRa](https://github.com/realspinner/SX1278_LoRa) for more information.

