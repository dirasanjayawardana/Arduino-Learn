
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

//Ubah alamat 0x27 dengan alamat i2C kamu

void setup(){
  lcd.begin (16,2); //LCD untuk ukuran 16x2
  }
  
void loop(){  
  lcd.setCursor(0, 0); //baris pertama   
  lcd.print("DIRA SANJAYA W");    
  lcd.setCursor(0, 1); //baris kedua   
  lcd.print("TEKNIK ELEKTRO");
}
