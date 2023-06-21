int pir = 2;
int led = 3;
int relay = 4;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT); 
  pinMode (relay, OUTPUT); 

}

void loop() {
  if(digitalRead(pir) == HIGH){
    digitalWrite(led, HIGH); 
    digitalWrite(relay, HIGH);
  }else{
      digitalWrite(led, LOW); 
      digitalWrite(relay, LOW);
  }
}
