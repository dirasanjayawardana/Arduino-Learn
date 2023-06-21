#include <LiquidCrystal_I2C.h>
#define echo 2   
#define trig 3     
float pulseTime = 0;  // variabe pulsa

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
 lcd.begin(16, 2);
 Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
}

void loop() {
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 pulseTime = pulseIn(echo, HIGH);
 int jarak = pulseTime / 58.26;     // konversi gelombang pulsa menjadi cm
 
 lcd.setCursor(0,0);
 lcd.print("Penggaris Digtal");

 lcd.setCursor(0,1);
 lcd.print("Jarak = ");
 lcd.print(jarak);
 lcd.print(" cm");

 Serial.print(jarak);
 Serial.println("cm");

 delay(500);
 lcd.clear();
}
