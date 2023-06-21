#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);    //UNTUK LCD 16X2
  lcd.setCursor(0,0);  //baris pertama
  lcd.print("selamat datang");
  lcd.setCursor(0,1);  //baris kedua
  lcd.print("wellcome");
}

void loop() {
  lcd.display(); //menampilkan teks yang telah dibuat pada void setup 
                 //lcd.noDisplay(); untuk mematikkan teks
  delay(400);  //lama waktu menampilkan teks
  int i;
  lcd.setCursor(0, 0);   // UNTUK BARIS PERTAMA
  lcd.print(" DIRA  SANJAYA  WARDANA");
  lcd.setCursor(0,1);    // UNTUK BARIS KEDUA
  lcd.print(" NPM : 1715031002");
  for (i = 0 ; i < 1; i ++) {
      lcd.scrollDisplayLeft();
      delay(400);
  }
}
