#define led 11

void setup() {
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int nilaiLDR=analogRead(0);
  analogWrite(11,nilaiLDR/4);

}
