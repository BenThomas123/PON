#!/bin/bash

# Run the program on an emulator (e.g., QEMU)
ELF_FILE="build/firmware.elf" # Replace with actual ELF file path

if [ ! -f "$ELF_FILE" ]; then
    echo "Error: ELF file not found. Build the project first."
    exit 1
fi

echo "Running program in QEMU..."
qemu-system-xtensa -M esp32 -kernel "$ELF_FILE"

if [ $? -eq 0 ]; then
    echo "Program executed successfully!"
else
    echo "Program execution failed!"
    exit 1
fi
