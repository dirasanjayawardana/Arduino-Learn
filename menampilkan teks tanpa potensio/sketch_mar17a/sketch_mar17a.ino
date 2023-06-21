#include <LiquidCrystal.h>
int Contrast=90;  //set kontrast 75%
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  analogWrite(6,Contrast);  // set kontrast di pint D6
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
  lcd.print("Teknik Elektro");
  lcd.display();
  delay(1500);
    
  lcd.clear();
  delay(1000);
  

}
