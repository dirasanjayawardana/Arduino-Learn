#include <LiquidCrystal.h>
#define echo 8   
#define trig 9     
float pulseTime = 0;  // variabe pulsa

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
 lcd.begin(16, 2);

 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
}

void loop() {
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 pulseTime = pulseIn(echo, HIGH);
 
 lcd.setCursor(0,0);
 lcd.print("Penggaris Digtal");

 lcd.setCursor(0,1);
 lcd.print("Jarak = ");
 lcd.print(round(pulseTime / 58.26), DEC);
 lcd.print(" cm");

 delay(300);
 lcd.clear();
}
