// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>

// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>

TCPClient client;

Ultrasonic ultrasonic(4);

unsigned long myChannelNumber = 2340172;    // change this to your channel number
const char * myWriteAPIKey = "B44PDA8DLYPC78E3"; // change this to your channels write API key

void setup() {
 ThingSpeak.begin(client);
 Serial.begin(9600);
}

void loop() {

 long RangeInCentimeters;

 Serial.println("The distance to obstacles in front is: ");
 
 RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
 Serial.print(RangeInCentimeters);//0~400cm
 Serial.println(" cm");
 
 ThingSpeak.writeField(myChannelNumber, 1, RangeInCentimeters, myWriteAPIKey);
 delay(20000); // ThingSpeak will only accept updates every 15 seconds.

}