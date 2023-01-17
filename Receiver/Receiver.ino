#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);
int a;
int buz = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
Serial.begin(9600);
BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//if BTSerial.available()

a = (BTSerial.read());
if (a == "O"){
digitalWrite(buz,HIGH);
}else
{
digitalWrite(buz,LOW);
}
}
