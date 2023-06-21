
#include <LiquidCrystal.h> //memanggil atau menggunakan library LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // pin yang digunakan pin 12, 11, 5, 4, 3, 2 nma variabel lcdd

void setup(){

  lcd.begin(16, 2);  // lcd yang digunakan 16x2
  
  lcd.print("Selamat Datang"); // tulisan selamat datang akan di cetak di baris pertama pd LCD
  
  lcd.setCursor(0,2);  // set posisi kursor kolom ke 0 baris ke 2 pada LCD
  
  lcd.print("Palcomtech");  // di baris ke 2 pada LCD akan di cetak kata Palcomtech

}

void loop(){

  //posisi teks dari kolom 0 bergerak ke kolom 60
  
  for (int counterposisi = 0; counterposisi < 60; counterposisi++){ 
  
    lcd.scrollDisplayLeft();  // teks bergerak ke kiri
    
    delay(500);
    
    }

  //posisi teks dari kolom 0 bergerak ke kolom 60
  
  for (int counterposisi = 0; counterposisi < 60; counterposisi++){
  
    lcd.scrollDisplayRight();// teks bergerak ke kanan
    
    delay(500);
    
    }

  //posisi teks dari kolom 0 bergerak ke kolom 60
  
  for (int counterposisi = 0; counterposisi < 60; counterposisi++){
  
    lcd.scrollDisplayLeft();
    
    delay(500);
    
    }
    delay(800);
}
