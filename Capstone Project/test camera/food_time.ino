#include <TinyMLShield.h>
#include <ChainableLED.h>
#include <Arduino_OV767X.h>

// Image buffer;
byte image[176 * 144 * 2]; // QCIF: 176x144 x 2 bytes per pixel (RGB565)
ChainableLED leds(11, 12, 1);

int bytesPerFrame;

void setup() {

  leds.setColorHSB(0, 0.0, 0.0, 0.0);
  Serial.begin(9600);

  while (!Serial);

  initializeShield();

  // Initialize the OV7675 camera
  if (!Camera.begin(QCIF, RGB565, 1, OV7675)) {
    Serial.println("Failed to initialize camera");
    while (1);
  }
  bytesPerFrame = Camera.width() * Camera.height() * Camera.bytesPerPixel();

  Serial.println("Welcome to FOOD TIME\n");
  Serial.println("When you ready, click the broad button to capture the image of food\n");
}

void loop() {

  int i = 0;
  bool clicked = readShieldButton();

  if (clicked) {

    Camera.readFrame(image);
    Serial.println("\nImage data will be printed out in 3 seconds...");
    delay(3000);

    for (int i = 0; i < bytesPerFrame - 1; i += 2) {
      Serial.print("0x");
      Serial.print(image[i+1], HEX);
      Serial.print(image[i], HEX);
      if (i != bytesPerFrame - 2) {
        Serial.print(", ");
      }
    }
  }

}