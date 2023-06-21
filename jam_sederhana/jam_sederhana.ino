#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int detik = 0;
int menit = 31;
int jam = 23;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
 detik +=1;
  
 if (detik >= 60){
 detik = 0;
 menit += 1;
 }

 if (menit >= 60){
 menit = 0;
 jam += 1;
 }

 if (jam >= 24){
 detik = 0;
 menit = 0;
 jam = 0;
 }


 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print(" Dira Sanjaya W");
 
 lcd.setCursor(1, 1);
 lcd.print("jam : ");
 
 lcd.setCursor(7, 1);
 lcd.print(jam);
 lcd.print(":");
 
 lcd.print(menit);
 lcd.print(":");
 
 lcd.print(detik);
 //delay untuk perhitungan
 delay(970);
}
