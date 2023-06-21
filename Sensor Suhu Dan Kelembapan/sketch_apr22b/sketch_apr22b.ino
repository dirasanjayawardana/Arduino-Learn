#include "DHT.h"
 
// pin digital yang digunakan
#define DHTPIN 2
 
// saat ini saya pakai sensor DHT11.
// uncomment sensor yang diinginkan 
 
#define DHTTYPE DHT22
//#define DHTTYPE DHT22   
//#define DHTTYPE DHT21 
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
}
 
void loop() {
  // Baca kelembaban
  float h = dht.readHumidity();
  // Baca temperatur dalam celcius
  float t = dht.readTemperature();
  //tampilkan pada serial monitor  
  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.print(" Suhu: ");
  Serial.println(t);
  delay(1000);

  
} 
