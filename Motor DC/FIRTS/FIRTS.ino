const int m1 = 3;

void setup(){
  pinMode(3, OUTPUT);
}

void loop(){
  for (int i=0; i<=255; i+=5){
    analogWrite(3, i);
    delay(200);
  }
}
