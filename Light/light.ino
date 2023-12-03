// This #include statement was automatically added by the Particle IDE.
#include <Grove_ChainableLED.h>

int ledColorIndex = 0;
int ledPin = A4;
double currentLightLevel;
unsigned long previousPublishMillis = 0;
unsigned long previousColorChangeMillis = 0;

const unsigned long publishInterval = 5000;

ChainableLED leds(A4, A5, 1);

void setup() {
    leds.init();
    leds.setColorHSB(0, 0.0, 0.0, 0.0);
    
    pinMode(A0, INPUT);
    pinMode(A4, OUTPUT);
}

void loop() {
    // Read the light level
    double lightAnalogVal = analogRead(A0);
    currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);
    
    // Check if it's time to publish the "light level" event
    unsigned long currentMillis = millis();
    if (currentMillis - previousPublishMillis >= publishInterval) {
        previousPublishMillis = currentMillis;
        Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
    }

    // Check if it's time to change LED color (every 2 seconds)
    if (currentMillis - previousColorChangeMillis >= 2000) {
        previousColorChangeMillis = currentMillis;
        
        if (currentLightLevel < 10) {
            digitalWrite(ledPin, HIGH); 
            leds.setColorRGB(0, random(255), random(255), random(255));
        }
        else {
            leds.setColorHSB(0, 0.0, 0.0, 0.0);
        }
    }
}