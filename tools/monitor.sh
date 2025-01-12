#!/bin/bash

# Monitor script to view serial output
PORT="/dev/ttyUSB0" # Replace with the correct serial port
BAUD_RATE="115200"

echo "Starting serial monitor on port $PORT at $BAUD_RATE baud..."
miniterm.py "$PORT" "$BAUD_RATE"
