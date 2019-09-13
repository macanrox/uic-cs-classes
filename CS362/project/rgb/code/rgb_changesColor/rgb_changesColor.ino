#include <SoftwareSerial.h>

SoftwareSerial bt(6, 5);

// pins for the LEDs:
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

int isRed;
int isGreen;
int isBlue;

void setup() {
  
  // initialize serial:
  Serial.begin(9600);

  //Prompt for user input
  Serial.println("Enter the red, green, and blue values separated by commas.");

  // make the pins outputs:
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}//end setup

void loop() {
  
  //prompt user for input
  while(Serial.available() > 0){

    isRed = Serial.parseInt();
    Serial.println(isRed);  //sanity test
    delay(500);
    isGreen = Serial.parseInt();
    Serial.println(isGreen);  //sanity test
    delay(500);
    isBlue = Serial.parseInt();
    Serial.println(isBlue);  //sanity test
    delay(500);

    //check if user inputs a newline
    //if(Serial.read() == '\n'){
      
      //sanity test
      Serial.println("I received: ");
      Serial.println(isRed);
      Serial.println(isGreen);
      Serial.println(isBlue);

      // fade the red, green, and blue legs of the LED:
      int red = isRed;
      int blue = isBlue;
      int green = isGreen;

      color(red, green, blue);
      
    //}
  }
  
}//end loop

//generates colors based on input
void color (unsigned char r, unsigned char g, unsigned char b)
{	 
  analogWrite(redPin, 255-r);
  analogWrite(greenPin, 255-g);	 
  analogWrite(bluePin, 255-b);
}




