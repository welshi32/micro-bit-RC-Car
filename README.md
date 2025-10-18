# micro-bit-RC-Car

## A simple micro:bit RC car prototype using the nRF5x family's built-in radio

> ⚠️ **WARNING**: This code is designed for **micro:bit v1** only.  
> The micro:bit v2 uses the NRF52 MCU, which may not be compatible with this library.

---

## What's this?

This project demonstrates a simple RC car prototype using the micro:bit v1's built-in radio.  
The car is controlled wirelessly via another micro:bit, sending **two separate values per packet** to control movement.  

It uses the [`NRF51_Radio_library`](https://github.com/tipih/NRF51_Radio_library) to communicate directly over the radio without BLE or SoftDevice.

---

## Features

- Micro:bit v1 only (NRF51 MCU)  
- Sends two separate control values per packet (e.g., speed and direction)  
- Arduino IDE compatible  
- Prebuilt `.hex` files for easy deployment  
- Simple and expandable codebase  

---

## Requirements

- 2 × **Micro:bit v1** boards (1 for the car, 1 for the controller)  
- Motor driver board (e.g., L298N or H-bridge compatible with Micro:bit)  
- Arduino IDE with **Micro:bit board package** installed  
- Batteries or power pack for the car (optional but recommended)  

---

## Getting Started

### Using Prebuilt Binaries

1. Download the latest `.hex` files from the releases section.  
2. Connect your Micro:bit via USB.  
3. Drag-and-drop `controller.hex` onto the controller Micro:bit.  
4. Drag-and-drop `car.hex` onto the car Micro:bit.  

### Building from Source

1. Clone this repository:

```bash
git clone https://github.com/welshi32/micro-bit-RC-Car.git
