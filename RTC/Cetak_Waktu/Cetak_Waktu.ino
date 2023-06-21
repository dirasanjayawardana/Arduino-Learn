#include <Wire.h>
#include "RTClib.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

RTC_DS1307 rtc;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  rtc.begin();
  Serial.begin(9600);
  
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W"); 
  lcd.setCursor(0,1);
  lcd.print("    wellcome");
  delay(2000);
  Wire.begin();

  if (! rtc.isrunning())
  {
  Serial.println("RTC is Not running");
  lcd.setCursor(0,0);
  lcd.print("RTC is Not running");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  lcd.clear();
  // Serial.println(now,DEC);
  Serial.print(now.day());
  lcd.setCursor(0,0);
  lcd.print("Tgl : ");
  lcd.print(now.day());
  
  Serial.print("/");
  lcd.print("/");
  
  Serial.print(now.month());
  lcd.print(now.month());

  Serial.print("/");
  lcd.print("/");
 

  Serial.print(now.year());
  lcd.print(now.year());
 
  Serial.print(" ");
 
  lcd.setCursor(0,1);
  lcd.print("Jam : ");
  Serial.print(now.hour());
  lcd.print(now.hour());
 
  Serial.print(":");
  lcd.print(":");
 
  Serial.print(now.minute());
  lcd.print(now.minute());
 
  Serial.print(":");
  lcd.print(":");
 
  Serial.println(now.second());
  lcd.print(now.second());
  delay(1000);


}
