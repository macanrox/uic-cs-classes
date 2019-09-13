#include <Wire.h>

const int ledPin = 5;
char c;

void setup()
{
  Wire.begin();                // join i2c bus with address #2
  //Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);
}

void loop()
{
  Wire.requestFrom(2,6);
  while(Wire.available()){
    c = Wire.read();
  }
  if(c != '\0'){
    analogWrite(ledPin, HIGH);
  }
  delay(100);
  analogWrite(ledPin, LOW);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
/*void requestEvent()
{
  Wire.write("hello "); // respond with message of 6 bytes
                       // as expected by master
}
*/
