/*
Adafruit Arduino - Lesson 14. Knob
*/
 
#include <Servo.h> 
 
Servo servo;  // declare the servo object
int potPin = 0;  // pin used to connect potentiometer
int servoPin = 9;  // variable to read value from analog pin
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin);  
} 
 
void loop() 
{ 
  int reading = analogRead(potPin);     // 0 to 1023
  int angle = reading;              // 0 to 180-ish
  ++angle %= 180;
  servo.write(angle);
  Serial.println(angle);  // debugging
  delay(100);  // slow it down a bit
} 
