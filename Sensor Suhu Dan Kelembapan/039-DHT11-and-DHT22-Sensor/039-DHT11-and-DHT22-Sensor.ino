#include <dht.h>                        //include the DHT library
#define DHTPin 2                        //define DHT pin
dht DHT;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  dht.setup(DHTPin);  
  lcd.begin(16,2);                      //initializes the LCD and specifies the dimensions
}
void loop() {
  float temp = DHT.temperature();
  float humi = DHT.humidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.print(" %");
  delay(2000);
}
