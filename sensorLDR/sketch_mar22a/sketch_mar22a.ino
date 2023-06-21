int ldr = A0;
int led= 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai = analogRead(ldr);
  Serial.print("nilai ldr");
  Serial.println(nilai);

  if (nilai<750){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
}
