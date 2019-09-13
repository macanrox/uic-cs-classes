/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library
#include <LiquidCrystal.h>

// init the lcd display according to the circuit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// indicate LCD size (16x2)
int screenWidth = 16;
int screenHeight = 2;

// two lines to display on screen
// line1 = scrolling, for the quote
String line1 = "The pessimist sees difficulty in every opportunity. The optimist sees the opportunity in every difficulty.";
// line2 = static, for the name
String line2 = "Bresia Prudente";

// some flags for the string and scrolling
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

void setup() {
  
  lcd.begin(screenWidth,screenHeight);
  
}//end setup

void loop() {
  
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(300);
  lcd.clear();
  
  if(stringStart == 0 && scrollCursor > 0){
    
    scrollCursor--;
    stringStop++;
    
  }//end if
  else if (stringStart == stringStop){
    
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
    
  }//end else if 
  else if (stringStop == line1.length() && scrollCursor == 0) {
    
    stringStart++;
    
  }//end else if 
  else {
    
    stringStart++;
    stringStop++;
  }//end else
  
}//end loop

