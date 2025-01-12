#!/bin/bash

# Debug script using gdb (or equivalent)
ELF_FILE="build/firmware.elf" # Replace with actual ELF file path

if [ ! -f "$ELF_FILE" ]; then
    echo "Error: ELF file not found. Build the project first."
    exit 1
fi

echo "Starting debug session with gdb..."
gdb-multiarch "$ELF_FILE"
