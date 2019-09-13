const int fsrPin = A0;
const int ledPin = 5;
char c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int fsrVal = analogRead(fsrPin);
  int ledVal = map(fsrVal,0,1023,0,255);  
  Serial.print("Sensor Sending = ");
  Serial.println(ledVal);
  
  if(ledVal > 0 ){
    Serial.write('a');
  }
  Serial.write('\0');
  
  if(Serial.available()>0){
    c = Serial.read();
  }
  
  Serial.print("Sensor Reading = ");
  int val = atoi(c);
  Serial.println(val);
  
  if(val >0){
    analogWrite(ledPin,HIGH);
  }
  delay(100);
  analogWrite(ledPin,LOW);

}
