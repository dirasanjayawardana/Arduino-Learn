#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 2);
    
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("DIRA  SANJAYA  WARDANA");
  for (int i = 0 ; i < 1; i ++) {
    lcd.scrollDisplayLeft();
    delay(400);
  }
}
void loop() {
 
  lcd.setCursor(1,1);
  lcd.print("NPM : 1715031002");
  
  

}
