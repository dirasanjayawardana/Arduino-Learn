const int PIR= 2;
const int Pinled = 3;


void setup() {
Serial.begin (9600);

pinMode (Pinled,OUTPUT);
pinMode (PIR,INPUT);
}

void loop() {
  
 int dataPIR = digitalRead(PIR);
 if(dataPIR==1)
 {
  digitalWrite(Pinled,HIGH);
 }else{
  digitalWrite(Pinled, LOW);
 }
}
