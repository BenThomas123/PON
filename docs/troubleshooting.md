# Troubleshooting Guide

This guide provides solutions to common issues encountered during setup, development, and deployment.

---

## General Issues

### Problem: Unable to Clone Repository
- **Cause:** Network issues or incorrect repository URL.
- **Solution:**
  1. Verify your internet connection.
  2. Ensure the repository URL is correct:
     ```bash
     git clone https://github.com/your-repo/pon-project.git
     ```

---

## Build Issues

### Problem: Build Fails
- **Cause:** Missing dependencies or syntax errors.
- **Solution:**
  1. Ensure you have all necessary dependencies installed:
     - For example, `gcc`, `make`, or `esp-idf`.
  2. Run `make clean` to remove old build artifacts:
     ```bash
     make clean
     ```
  3. Try building again:
     ```bash
     ./tools/build.sh
     ```

---

## Flashing Issues

### Problem: Flash Script Fails
- **Cause:** Incorrect port or missing binary file.
- **Solution:**
  1. Verify the ESP32 is connected to the correct port:
     ```bash
     ls /dev/ttyUSB*
     ```
  2. Ensure the binary file exists:
     ```bash
     ls build/firmware.bin
     ```
  3. Run the `flash.sh` script with the correct port:
     ```bash
     ./tools/flash.sh
     ```

### Problem: Cannot Detect ESP32
- **Cause:** USB drivers not installed.
- **Solution:**
  - Install the appropriate drivers for your platform:
    - **Windows:** CP2102 or CH340 drivers.
    - **Linux:** Add the user to the `dialout` group:
      ```bash
      sudo usermod -aG dialout $USER
      ```

---

## Debugging Issues

### Problem: Debug Session Fails to Start
- **Cause:** Missing or incorrect ELF file.
- **Solution:**
  1. Verify the ELF file exists:
     ```bash
     ls build/firmware.elf
     ```
  2. Rebuild the project to regenerate the ELF file:
     ```bash
     ./tools/build.sh
     ```

---

## Runtime Issues

### Problem: No Output in Serial Monitor
- **Cause:** Incorrect serial port or baud rate.
- **Solution:**
  1. Verify the port and baud rate in `monitor.sh`:
     ```bash
     PORT="/dev/ttyUSB0"
     BAUD_RATE="115200"
     ```
  2. Run the serial monitor:
     ```bash
     ./tools/monitor.sh
     ```

### Problem: Device Not Responding
- **Cause:** Firmware crash or hardware issue.
- **Solution:**
  1. Perform a hardware reset by pressing the reset button on the ESP32.
  2. Re-flash the firmware using:
     ```bash
     ./tools/flash.sh
     ```

---

## Network Issues

### Problem: Unable to Connect to Network
- **Cause:** Incorrect network credentials or protocol settings.
- **Solution:**
  1. Verify Wi-Fi credentials in the configuration file.
  2. Check the network status using:
     ```bash
     GET /network/status
     ```

### Problem: Protocol Not Switching
- **Cause:** PON command not reaching the Edge Gateway.
- **Solution:**
  1. Verify that the PON is sending the correct protocol update message.
  2. Use the serial monitor to debug the Edge Gateway logs.

---

## OTA Update Issues

### Problem: OTA Update Fails
- **Cause:** Incorrect firmware URL or network error.
- **Solution:**
  1. Verify the OTA URL is correct:
     ```json
     {
       "version": "1.0.1",
       "url": "http://example.com/firmware.bin"
     }
     ```
  2. Check network connectivity using:
     ```bash
     ping example.com
     ```
  3. Retry the update using the OTA API:
     ```bash
     POST /ota/update
     ```

---

## Security Issues

### Problem: Secure Boot Fails
- **Cause:** Firmware integrity check failed.
- **Solution:**
  1. Verify the firmware hash matches the expected value.
  2. Rebuild the firmware and flash it again.

### Problem: TLS Handshake Fails
- **Cause:** Certificate mismatch or expired certificate.
- **Solution:**
  1. Verify the TLS certificate used by the server.
  2. Update the certificate if necessary.

---

## Other Issues

### Problem: Logs Are Inconsistent or Missing
- **Cause:** Logging module not initialized.
- **Solution:**
  1. Ensure the logging module is initialized during system startup.
  2. Check log levels in the configuration file.

---

## Contact Support
If the above solutions do not resolve your issue, please contact the development team:
- **Email:** support@example.com
- **GitHub Issues:** [https://github.com/your-repo/issues](https://github.com/your-repo/issues)
