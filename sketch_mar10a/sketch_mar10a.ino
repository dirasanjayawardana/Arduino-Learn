#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
void setup()
{
  lcd.begin(16, 2);
}
int i;
void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DIRA SANJAYA");
  lcd.setCursor(0, 1);
  lcd.print("WARDANA");
  delay(2000);

  lcd.clear();
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("=Robot NF-308=");
  for (i=0; i<16; i++)
  {
    lcd.scrollDisplayLeft();  
    delay(500);
  }
  lcd.clear();
  delay(1000);
}
