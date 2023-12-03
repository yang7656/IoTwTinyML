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

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

Your Name - [Your Email](mailto:your-email@example.com)

Project Link: [https://github.com/your-username/your-repo-name](https://github.com/your-username/your-repo-name)

## Acknowledgments

- [Particle](https://www.particle.io/)
- [Grove System](https://www.seeedstudio.com/)
