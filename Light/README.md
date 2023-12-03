# Particle Light-Responsive LED Project

This repository contains the source code for a project using a Particle device (such as Photon or Electron) equipped with a Grove Chainable LED and a light sensor. The project aims to create a light-responsive LED system where the LED changes color based on the ambient light intensity.

## Features

- **Light Sensing**: Measures the ambient light level using a light sensor.
- **Responsive LED**: The LED changes color when the ambient light falls below a certain threshold.
- **Cloud Integration**: Regularly publishes the light level data to the Particle Cloud.

## Hardware Requirements

- Particle Photon/Electron
- Grove Chainable LED
- Light Sensor (Analog)

## Software Requirements

- [Particle IDE](https://build.particle.io/)
- [Grove ChainableLED Library](https://github.com/pjpmarques/ChainableLED)

## Installation

1. Clone this repository to your local machine.
2. Open the Particle IDE and import the project.
3. Connect your Particle device to your computer.
4. Flash the code to your Particle device using the Particle IDE.

## Usage

- The LED will light up in a random color when the ambient light level is low.
- The light level is published to the Particle Cloud at regular intervals, which can be monitored for data analysis or integration with other systems.
