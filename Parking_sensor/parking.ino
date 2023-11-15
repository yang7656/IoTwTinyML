// This #include statement was automatically added by the Particle IDE.
#include <Grove_ChainableLED.h>
#include <Grove-Ultrasonic-Ranger.h>
#include <ThingSpeak.h>


TCPClient client;
Ultrasonic ultrasonic(4);
ChainableLED leds(A4, A5, 1);

unsigned long myChannelNumber = 2340172;    // Change to your channel number
const char * myWriteAPIKey = "B44PDA8DLYPC78E3"; // Change to your channel's write API key

int ledPin = D2;  // Change to the pin your LED is connected to

void setup() {
    leds.init();
    leds.setColorHSB(0, 0.0, 0.0, 0.0);
    
    ThingSpeak.begin(client);
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); // Set the LED pin as output
}

void loop() {
    long rangeInCentimeters = ultrasonic.MeasureInCentimeters();
    float rangeInInches = rangeInCentimeters * 0.393701; // Convert cm to inches

    Serial.print("Distance: ");
    Serial.print(rangeInInches);
    Serial.println(" inches");

    if (rangeInInches < 4) {
        digitalWrite(ledPin, HIGH); // Turn the LED on
        leds.setColorHSB(0, 0.0, 1.0, 0.5);
        Particle.publish("car_status", "Car is parked", PRIVATE); // Publish the event
    } else {
        leds.setColorHSB(0, 0.0, 0.0, 0.0);
        digitalWrite(ledPin, LOW); // Turn the LED off
    }
    
    ThingSpeak.writeField(myChannelNumber, 1, rangeInCentimeters, myWriteAPIKey);
    delay(20000); // ThingSpeak update limit
}