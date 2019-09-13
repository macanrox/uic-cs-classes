#include <SoftwareSerial.h>

SoftwareSerial bt(6, 5);

// pins for the LEDs:
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

//variables for rgb input
int isRed;
int isGreen;
int isBlue;

void setup() {

  // initialize serial and bluetooth:
  bt.begin(9600);  //to read in values from bluetooth
  Serial.begin(9600);  //for serial monitor

  //Prompt for user input
  Serial.println("Enter the red, green, and blue values separated by commas.");

  // make the pins outputs:
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}//end setup

void loop() {

  //check if there's anything coming from the bluetooth
  if(bt.available() > 0){

    //parse each color for integers
    isRed = bt.parseInt();
    isGreen = bt.parseInt();
    isBlue = bt.parseInt();

    //sanity test
    Serial.println("I received: ");
    Serial.print("R: ");
    Serial.println(isRed);
    Serial.print("G: ");
    Serial.println(isGreen);
    Serial.print("B: ");
    Serial.println(isBlue);

    //for any newline
    if(bt.parseInt() == 0){
      bt.flush();  //flushes the value
      Serial.println("Bluetooth serial has been flushed");  //debug
    }//end if

    // fade the red, green, and blue legs of the LED:
    int red = isRed;
    int blue = isBlue;
    int green = isGreen;
    
    //print the colors
    color(red, green, blue);
    
  }//end if(bt.available()...

}//end loop

//color generates colors based on input
void color (unsigned char r, unsigned char g, unsigned char b)
{	 
  analogWrite(redPin, 255-r);
  analogWrite(greenPin, 255-g);	 
  analogWrite(bluePin, 255-b);
}//end color
