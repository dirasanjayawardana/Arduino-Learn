#define LED1 2
#define LED2 3
int waktu1 = 0;
bool kondisi_led = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
  unsigned long waktu2 = millis();
  if ((waktu2-waktu1)>=500){
    waktu1 = waktu2;

    if (kondisi_led == 0){
      kondisi_led = 1;
     }
    else {
      kondisi_led = 0;
    }
  }

  digitalWrite(LED1, kondisi_led);

  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500); 
}
