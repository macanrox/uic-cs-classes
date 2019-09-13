/*
  CS 362 - Lab #4, Part #1
  Bresia Prudente, bprude2
*/

int lightPin = 0;  //define a pin for the photoresistor
int ledPin = 11;  //define a pin for the LED

void setup(){
  
  Serial.begin(9600);  //begin serial communication
  pinMode( ledPin, OUTPUT );  //
  
}//end setup

void loop(){
  
  Serial.println( analogRead( lightPin ) );  //write the value of the photoresistor to the serial
  analogWrite( ledPin, analogRead(lightPin)/4 );  //send the value to the ledPin to analog 0
                                                  //the value is dependent on the resistor type 
                                                  //4 for 1kOhm
  delay(10);  //delay based on light reponse
  
}//end loop
