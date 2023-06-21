#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 1);
}

void loop() {
  int i;
 
  lcd.setCursor(0, 0);
  lcd.print("CODEJUNK STUDIO MENGUCAPKAN SELAMAT MENJALANKAN IBADAH PUASA 1437 H");
  for (i = 0 ; i < 16; i ++) {
      lcd.scrollDisplayLeft();
      delay(400);
  }
}
