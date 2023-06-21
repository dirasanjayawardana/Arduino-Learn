
#include <dht.h>
#define DATA_PIN 2 // Definisi Pin untuk DHT22

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
dht DHT; // Buat DHT object

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600); 
}
void loop() {
  
  int readData = DHT.read22(DATA_PIN); // baca Data dari sensor
  float t = DHT.temperature; // Ambil nilai Suhu
  float h = DHT.humidity; // Ambil nilai Kelembaban
  
  // Mencetak output ke Serial monitor
  Serial.print("SUHU = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    KELEMBABAN = ");
  Serial.print(h);
  Serial.println(" % ");
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print(" %");
  delay(2000);
}
