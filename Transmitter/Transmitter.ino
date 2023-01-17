#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
int a;
const int trigPin = 9;
const int echoPin = 8;
// defines variables
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
BTSerial.begin(9600);
}

void loop() {
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance < 100)
  {
BTSerial.write("O");
Serial.println("activated");
}
if(distance > 100)
{
BTSerial.write("F");
Serial.println("NOT ACTIVATED");
}
}
