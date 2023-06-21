const int servo = 2;
int pulsa;
void setup(){
  pinMode(servo, OUTPUT);
}

void loop(){
  //delay 900=0, delay 2600=180
  
  for (pulsa=0;pulsa<=1700;pulsa+=50){
    digitalWrite(servo, HIGH);
    delayMicroseconds(pulsa);
    digitalWrite(servo, LOW);
    delay(25);
  }
  for (pulsa=1700;pulsa>=0;pulsa-=50){
    digitalWrite(servo, HIGH);
    delayMicroseconds(pulsa);
    digitalWrite(servo, LOW);
    delay(25);
  }
  
}
