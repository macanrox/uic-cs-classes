#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String printMsg = "Hello World";
const int button = 9;
int buttonState = 0;  //determines if the button is used or not

void setup(){
  
  lcd.begin(16, 2)  //set up the LCD display
  pinMode(button, INPUT);
  
}//end setup

void loop() {
  
  buttonState = digitalRead(button);
  
    // Print a message to the LCD.
  if (buttonState == HIGH)   
    printMsg = "Interrupt Recieved!";
  else
    printMsg = "Hello, Word!";
      
  //Point the cursor to the row it should begin in
  lcd.setCursor(0, 1);
  lcd.print(printMsg);
    
}
