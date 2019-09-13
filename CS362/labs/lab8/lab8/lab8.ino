/*
 * CS 361 - Lab 8
 *
 * Bresia Prudente (bprude2)
 */

int fsr = 0;
int pc = 1;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  Serial.println(analogRead(fsr));  // fsr
  Serial.println(analogRead(pc));  // photocell
  // wait a bit for the analog-to-digital converter 
  // to stabilize after the last reading:
  delay(2);
}
