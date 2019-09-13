#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(6, 5);
 
void setup() {
  Serial.begin(9600);
  Serial.println("Hello, Serial Monitor");
 
  // The data rate for the SoftwareSerial port needs to 
  // match the data rate for your bluetooth board.
  mySerial.begin(9600);
  mySerial.println("Hello, Bluetooth");
}
 
void loop() {
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
