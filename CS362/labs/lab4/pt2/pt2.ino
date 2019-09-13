/*
  CS 362 - Lab #4, Part #2
  Bresia Prudente, bprude2
 */

// include the library
#include <LiquidCrystal.h>

// init the lcd display according to the circuit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// indicate LCD size (16x2)
int screenWidth = 16;
int screenHeight = 2;

// Static string for displaying brightness information
String brightnessState;

int stringStart, stringStop = 0;
int scrollCursor = 16;

// insert photocell variables
int photoCellPin = 0;  // cell and 10k Ohm resistor is connected to analog 0
int photoCellReading;  // analog reading from analog resistor divider

void setup() {
  
  lcd.begin(screenWidth, screenHeight);  // use the lcd size to display the info properly
  Serial.begin(9600);  // debugging
  
}//end setup

void loop() {
  
  photoCellReading = analogRead(photoCellPin);
  Serial.println(photoCellReading);  // debugging
  
  // Determine ranges and display accordingly
  if (photoCellReading < 10) {
    brightnessState = "Dark";
  }//end if
  else if (photoCellReading < 200) {
    brightnessState = "Dim";
  }//end else if
  else if (photoCellReading < 500) {
    brightnessState = "Light";
  }//end else if
  else if (photoCellReading < 800) {
    brightnessState = "Bright";
  }//end else if
  else if (photoCellReading > 800) {
    brightnessState = "Very Bright";
  }//end else if
  else {
    brightnessState = "Can't determine value.";
  }//end else
  
  // Set and display the topmost row
  lcd.setCursor(0,0);
  lcd.print("Value: ");
  lcd.print(photoCellReading);
  
  // Set and display the second row
  lcd.setCursor(0, 1);
  lcd.print(brightnessState);
  
  delay(1000);  // delay each information for 1 second
  lcd.clear();  // reset the screen
  
}//end loop

