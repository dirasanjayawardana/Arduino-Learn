#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

//inialisasi masing2 pin tombol
const int pinReset = 13;
const int pinStop = 12;
const int pinStart = 11;

//inialisasi masing2 nilai awal waktu
int sepersepuluhDetik = 0;
int detik = 0;
int menit = 0;
int jam = 0;

//inialisasi nilai awal dari state
int state = 0;

void setup()
{
 //inialisasi status pin I/O
 pinMode (pinReset, INPUT);
 pinMode (pinStop, INPUT);
 pinMode (pinStart, INPUT);

//menulis status awal masing2 pin tombsol
 digitalWrite(pinReset, HIGH);
 digitalWrite(pinStop, HIGH);
 digitalWrite(pinStart, HIGH);

//inialisasi jumlah baris dan kolom lcd
 lcd.begin(16, 2);
}

void loop()
{
 //jika tombol reset ditekan
 if (digitalRead(pinReset) == LOW)
 {
 //niali state menjadi = 0
 state = 0;
 }

//jika tombol stop ditekan
 else if (digitalRead(pinStop) == LOW)
 {
 //niali state menjadi = 1
 state = 1;
 }

//jika tombol start ditekan
 else if (digitalRead(pinStart) == LOW)
 {
 //nilai state menjadi = 2
 state = 2;
 }

//jika nilai state =0, maka
 if (state == 0)
 {
 //nilai masing2 variabel menjadi demikian
 sepersepuluhDetik = 0;
 detik = 0;
 menit = 0;
 jam = 0;
 }

//jika nilai state = 1
 else if (state == 1)
 {
 //nilai masing2 variabel tetap
 sepersepuluhDetik = sepersepuluhDetik;
 detik = detik;
 menit = menit;
 jam = jam;
 }

//jika nilai state = 2
 else if (state == 2)
 {
 //nilai sepersepuluhDetik bertambah terus
 sepersepuluhDetik++;
 }

//jika nilai sepersepuluhDetik lebih besar sama dengan 10
 if (sepersepuluhDetik >= 10)
 {
 //nilai sepersepuluhDetik menjadi 0 lagi
 sepersepuluhDetik = 0;
 //nilai detik bertambah 1
 detik += 1;
 }

//jika niali detik lebih dari sama dengan 60
 if (detik >= 60)
 {
 //niali detik menjadi 0
 detik = 0;
 //nilai menit bertambah 1
 menit += 1;
 }

//jika nilai menit lebih dari sama dengan 60
 if (menit >= 60)
 {
 //nilai menit kembali menjadi 0
 menit = 0;
 //nilai jam bertambah 1
 jam += 1;
 }

//menuliskan pembacaan stopwatch pada lcd
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Stopwatch");
 lcd.setCursor(0, 1);
 lcd.print(sepersepuluhDetik);
 lcd.setCursor(2, 1);
 lcd.print(":");
 lcd.setCursor(3, 1);
 lcd.print(detik);
 lcd.setCursor(5, 1);
 lcd.print(":");
 lcd.setCursor(6, 1);
 lcd.print(menit);
 lcd.setCursor(8, 1);
 lcd.print(":");
 lcd.setCursor(9, 1);
 lcd.print(jam);
 //delay untuk perhitungan sepersepuluhDetik
 delay(100);
}
