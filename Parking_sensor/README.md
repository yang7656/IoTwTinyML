# Particle Ultrasonic Parking Assistant

This repository contains the source code for an ultrasonic parking assistant using a Particle device, a Grove Ultrasonic Ranger, and a Grove Chainable LED. The project aims to detect the presence of a car within a certain distance and visually indicate it using an LED. Additionally, the system publishes the distance data to ThingSpeak for remote monitoring.

## Features

- **Ultrasonic Distance Measurement**: Uses the Grove Ultrasonic Ranger to measure the distance.
- **LED Indicator**: The LED lights up when the car is parked within a specific range.
- **ThingSpeak Integration**: Distance data is sent to ThingSpeak for logging and analysis.

## Hardware Requirements

- Particle Photon/Electron
- Grove Chainable LED
- Grove Ultrasonic Ranger
- General-purpose LED
- Connecting wires

## Software Requirements

- [Particle IDE](https://build.particle.io/)
- [Grove ChainableLED Library](https://github.com/pjpmarques/ChainableLED)
- [Grove Ultrasonic Ranger Library](https://github.com/Seeed-Studio/Grove_Ultrasonic_Ranger)
- [ThingSpeak Library](https://github.com/mathworks/thingspeak-particle)

## Installation

1. Clone this repository to your local machine.
2. Open the Particle IDE and import the project.
3. Connect your Particle device to your computer.
4. Flash the code to your Particle device using the Particle IDE.

## Configuration

- Update `myChannelNumber` and `myWriteAPIKey` with your ThingSpeak channel number and write API key.
- Adjust the pin assignments as necessary based on your hardware setup.

## Usage

- Place the ultrasonic sensor in a suitable position to detect the presence of a car.
- When the car is detected within a predefined range (less than 4 inches), the LED will light up, and a "Car is parked" event is published.
- The distance data is sent to ThingSpeak every 20 seconds for logging and analysis.
