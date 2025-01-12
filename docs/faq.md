# Frequently Asked Questions (FAQ)

## General
### What is this project?
This project implements a Protocol Orchestrator Node (PON) for managing dynamic protocol switching in IoT networks.

### Why does the PON use ESP32?
The ESP32 provides a cost-effective, powerful platform for IoT projects with integrated Wi-Fi, Bluetooth, and sufficient processing power.

## Development
### How do I build the project?
Run `./tools/build.sh` to build the project.

### How do I flash the firmware to the ESP32?
Use the `./tools/flash.sh` script to upload the firmware.

## Security
### How is the system secured?
The system uses TLS for secure communication, secure boot to verify firmware integrity, and an authentication API for access control.
