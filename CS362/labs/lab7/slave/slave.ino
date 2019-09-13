int myTouch;
int youTouch;
const int fsrPin = A0;
const int ledPin = 5;

char c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}//end setup

void loop() {
  // put your main code here, to run repeatedly:
  int myTouch = analogRead(fsrPin);
  
  Serial.print("my touch sensor = ");
 // Serial.println(fsrVal)
  Serial.println(myTouch);
  
  if(myTouch > 0 ){
    Serial.write('a');
  }
  Serial.write('\0');
  

  if(Serial.available()){
    youTouch = Serial.read();
    
  }

  //youTouch = atoi(c);
  
  Serial.print("Sensor Reading = ");

  Serial.println(youTouch);
  
  if(youTouch >0){
    analogWrite(ledPin,HIGH);
  }
  else{
    analogWrite(ledPin, LOW);
  delay(100);
  }

}//end loop
