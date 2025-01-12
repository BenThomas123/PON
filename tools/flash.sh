#!/bin/bash

# Flash script for uploading firmware to ESP32
PORT="/dev/ttyUSB0" # Replace with the correct serial port
BAUD_RATE="115200"
BIN_FILE="build/firmware.bin" # Replace with the actual binary file path

if [ ! -f "$BIN_FILE" ]; then
    echo "Error: Binary file not found. Build the project first."
    exit 1
fi

echo "Flashing firmware to ESP32..."
esptool.py --chip esp32 --port "$PORT" --baud "$BAUD_RATE" write_flash -z 0x1000 "$BIN_FILE"

if [ $? -eq 0 ]; then
    echo "Flash successful!"
else
    echo "Flash failed!"
    exit 1
fi
