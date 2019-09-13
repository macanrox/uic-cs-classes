

// constants won't change. They're used here to 
// set pin numbers:
const int increButton = 4;  // incrementing button
const int decreButton = 5;  // decrementing button
//all led pins
const int ledPin = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;

// variables will change:
int incrementState = 0;         // current state of increment button
int decrementState = 0;         // current state of decrement button
int lastIncrementState = 0;     // previous state of increment button
int lastDecrementState = 0;     // previous state of decrement button
int counter = 0;                // stores count

void setup() {
  
  // initialize all LED pins as outputs:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  // initialize the pushbutton pins as inputs:
  pinMode(increButton, INPUT);
  pinMode(decreButton, INPUT);
  Serial.begin(9600);
  
}//end void setup()

void loop(){
  // read the state of the pushbutton value:
  //since there are two buttons, read both increment and decrement buttons
  incrementState = digitalRead(increButton);
  decrementState = digitalRead(decreButton);

  // check if current increment button state is the same as the previous
  if(incrementState != lastIncrementState){
    if(incrementState == LOW){  //increment button is pressed
      counter = counter + 1;  // increase counter
      if(counter == 8){
        counter = 0;  //reset counter since we can't have more than 3
      }//end if
      Serial.println(counter);  //print it out on the serial monitor
      delay(1000);  //wait for a second
    }//end if
  }//end if
  lastIncrementState = incrementState;
  
  // check if current increment button state is the same as the previous
  if(decrementState != lastDecrementState){
    if(decrementState == LOW){  //decrement button is pressed
      counter = counter - 1;  // decrease counter
      if(counter < 0){
        counter = 0;
      }//end if
      Serial.println(counter);  //print it out on the serial monitor
      delay(1000);  //wait for a second
    }//end if
  }//end if
  lastDecrementState = decrementState;
  
  // light up pins according to the counter
  switch(counter){

    case 0: digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            break;
    case 1: digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            break;
    case 2: digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, LOW);
            break;
    case 3: digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, HIGH);
            break;
    case 4: digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, HIGH);
            break;
    case 5: digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            break;
    case 6: digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            break;
    default: digitalWrite(ledPin, LOW);
	     digitalWrite(ledPin2, LOW);
	     digitalWrite(ledPin3, LOW);
	     break;            
  }//end switch

}//end void loop()
