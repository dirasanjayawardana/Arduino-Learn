#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);    //UNTUK LCD 16X2
}

void loop() {
  lcd.setCursor(0,0);  //baris pertama
  lcd.print(" selamat datang");
  lcd.setCursor(0,1);  //baris kedua
  lcd.print("   'wellcome' ");
  delay(1500);
  
  lcd.clear();
  delay(1000);
  
  lcd.setCursor(0, 0);   // UNTUK BARIS PERTAMA
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);    // UNTUK BARIS KEDUA
  lcd.print("NPM : 1715031002");
  lcd.display();
  delay(1500);
    
  lcd.clear();
  delay(1000);
  
  lcd.setCursor(0, 0);   // UNTUK BARIS PERTAMA
  lcd.print(" Teknik Elektro");
  lcd.setCursor(0,1);    // UNTUK BARIS KEDUA
  lcd.print("   UNILA 2017    ");
  lcd.display();
  delay(1500);
   
  lcd.clear();
  delay(1000);
}
