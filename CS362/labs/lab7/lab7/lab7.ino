/*
 * CS 361 - Lab 7
 *
 * Bresia Prudente (bprude2)
 * Saleha Amreen (samree2)
 *
 */

int ledPin = 11;
int fsrAnalogPin = 0;
int inByte;
int fsrRead;
int ledBrightness;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(fsrAnalogPin, INPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
    inByte = Serial.read();  //read incoming byte
    if(inByte == 'H')
      digitalWrite(ledPin, HIGH);
    if(inByte == 'L')
      digitalWrite(ledPin, LOW);
  }
  
  fsrRead = analogRead(fsrAnalogPin);
  
  //If it's not low
  if(fsrRead != LOW)
    Serial.write('H');
  else
    Serial.write('L');
}
