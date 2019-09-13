/*
 * CS 362 - Lab #6
 * Bresia Prudente (bprude2)
 *
 */

#include <LiquidCrystal.h>
#include <Time.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int inSecond = 0;
int inMinute = 0;
int inHour = 0;

void setup(){

  Serial.begin(9600);
  lcd.begin(16, 2);

  //Prompt user input for hours
  Serial.println("Enter the hour.");
  while(Serial.available() == 0){}
  inHour = Serial.parseInt();  // numerical char into integer
  Serial.print("Hours I received: ");
  Serial.println(inHour);
  // Make sure the hours are valid
  if(inHour > 24){
    Serial.println("Hour value is invalid!");
    inHour = 0;  // print this as default
  }

  //Prompt user input for minutes
  Serial.println("Enter the minute.");
  while(Serial.available() == 0){}
  inMinute = Serial.parseInt();  // numerial char into integer
  Serial.print("Minutes I received: ");
  Serial.println(inMinute);
  // Make sure the minutes are valid
  if(inMinute > 60){
    Serial.println("Minute value is invalid!");
    inMinute = 0;  // print this as default
  }
}//end setup

void loop(){   

  // To print the time
  lcd.setCursor(1,0);
  // Print the hour
  if(inHour < 10){
    lcd.print('0');
    lcd.print(inHour);
  }
  else
    lcd.print(inHour);
  // Print the minute
  lcd.print(":");
  if(inMinute < 10){
    lcd.print('0');
    lcd.print(inMinute);
  }
  else
    lcd.print(inMinute);
  // Print the seconds
  lcd.print(":"); 
  if(inSecond < 10){
    lcd.print('0');
    lcd.print(inSecond);
  }
  else
    lcd.print(inSecond);

  // Increment some values as time goes on
  if(inSecond == 60){
    inMinute++;
    inSecond = 0;
  }
  if(inMinute == 60){
    inHour++;
    inMinute = 0;
  }
  // Reset hours once it reaches 24
  if(inHour == 24){
    inHour = 0;
  }

  inSecond++;  //increment seconds
  delay(150);  //indicates tick speed

}//end loop
