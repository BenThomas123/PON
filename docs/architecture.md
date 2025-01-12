
---

#### **`architecture.md`**

```markdown
# System Architecture

This document provides an overview of the system's architecture.

## Components
- **Protocol Orchestrator Node (PON):** Manages protocol switching and system-level tasks.
- **Edge Gateway:** Intermediates communication between the IoT devices and the central network.
- **IoT Devices:** Sensors, actuators, and other endpoints.

## Communication Flow
1. The PON sends protocol update commands to the Edge Gateway.
2. The Edge Gateway adjusts its configuration and relays instructions to IoT devices.
3. Status updates flow from IoT devices to the Edge Gateway, and then to the PON.

## Key Modules
- **Kernel:** Handles task scheduling and inter-process communication.
- **Middleware:** Manages protocol switching, message queuing, and updates.
- **Network Stack:** Implements TCP/IP, MQTT, and CoAP protocols.
- **Security Layer:** Provides encryption, authentication, and secure boot mechanisms.
