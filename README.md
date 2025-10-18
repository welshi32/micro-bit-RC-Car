# nFR5-RC-Car

## A simple RC car prototype using the nRF5x family's built-in radio

> ⚠️ **WARNING**: Make sure you choose the correct binary for your device, or this WILL NOT WORK. Prebuilt binaries are only for nRF51822/nRF52833 SoCs. If you have a board with a diffferent nRF5x SoC, you will have to compile yourself.  

---

## What's this?

This project demonstrates a simple RC car prototype using the nRF5x's built-in radio.  
The car is controlled wirelessly via another board, sending **two separate values per packet** to control movement.  

It uses the [`NRF51_Radio_library`](https://github.com/tipih/NRF51_Radio_library)/[`nrf_to_nrf library`](https://github.com/TMRh20/nrf_to_nrf) to communicate directly over the radio without BLE or SoftDevice.

---

## Features

- Works with micro:bit v1, v2 and any NRF51/52 dev board since of a recent update
- Sends two separate control values per packet (e.g., speed and direction)  
- Arduino IDE compatible  
- Prebuilt `.hex` files for easy deployment  
- Simple and expandable codebase  

---

## Requirements

- 2 × **nRF5x** dev boards (1 for the car, 1 for the controller)  
- Motor driver board (e.g., DRV8833, TB6612FNG or any H-bridge)  
- Arduino IDE with **nRF5x board package** installed  
- Batteries or power pack for the car (optional but recommended)  

---

## Getting Started

### Using Prebuilt Binaries

1. Download the latest `.hex` files from the releases section.  
2. Connect your board via USB.  
3. Drag-and-drop `NRF52_tx.hex/microbit_tx.hex` onto the controller MCU.  
4. Drag-and-drop `NRF52_rx.hex/microbit_rx.hex` onto the car MCU.  

### Building from Source

1. Download the **.ino** file for your exact SoC(microbit_rx/tx.ino for nRF51, NRF52_rx/tx.ino for nRF52)
2. Make sure you have **Arduino IDE** and the **arduino-nRF5 & Adafruit_nRF52_Arduino** cores installed
3. Install the [`NRF51_Radio_library`](https://github.com/tipih/NRF51_Radio_library) and [`nrf_to_nrf library`](https://github.com/TMRh20/nrf_to_nrf) library
4. Select your board and port and press **Upload**
5. Wait for the **Done uploading** message

### Bugs/feature reports
I am usually free, if you find a bug or want to suggest a new feature, feel free to open an issue, I'll look into it when I can.
