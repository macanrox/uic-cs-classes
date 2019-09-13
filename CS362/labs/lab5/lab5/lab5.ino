/*
  CS 362 - Lab 5
  Bresia Prudente (bprude2)
*/

#include <Servo.h>

// Declare variables
Servo servo;  // declare the servo object
int potPin = 0;  // pin used to connect potentiometer
int servoPin = 9;  // variable to read value from analog pin
int inPin = 7;  // pin number for input
int motorPin = 13;  // pin number for output

int dcState = HIGH;
int previous = LOW;

long time = 0;
long debounce = 50;

void setup(){
  
  servo.attach(servoPin);
 
  pinMode(inPin, INPUT);
  digitalWrite(inPin, HIGH);   // turn on the built in pull-up resistor
  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);  //debugging 
}//end setup

void loop(){
  
  // Servo and potentiometer
  int reading = analogRead(potPin);     // gives value of 0 to 1023
  int angle = reading / 6;  //divide analog value within constraints of 0 to 170
  servo.write(angle);
  Serial.println(angle);  // debugging
  delay(100);  // slow it down a bit
  
  
  // Tilt sensor and dc motor
  int switchstate;
  reading = digitalRead(inPin);
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    time = millis();  //reset debouncing timer
  }
 
  // Determine state of the dc motor
  if ((millis() - time) > debounce) {    
    switchstate = reading;
 
     // Now invert the output on dc motor
    if (switchstate == HIGH)
      dcState = LOW;
    else
      dcState = HIGH;    
  }
  digitalWrite(motorPin, dcState);
  previous = reading;  // save a tally to the previous state
  
}//end loop
