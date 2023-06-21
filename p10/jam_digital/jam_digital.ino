/* ********************** code ini dibuat oleh: mfahrudinafi89@gmail.com ********************* 
2  * ******************** https://github.com/fahrudinafif89/jam-digital-p10 ******************** 
3  * *************** atau lebih lengkapnya lagi klik:https://youtu.be/ULKmqvRXUJQ*************** 
4  *  
5  * arduino A5 >> SCL DS3231 
6  *         A4 >> SDA DS3231 
7  *untuk koneksi arduino ke led matrix p10 menggunkan connector jadi tinggal pug and play 
8  */ 
#include <DMD.h> 
#include <TimerOne.h> 
#include <Wire.h> 
#include <Sodaq_DS3231.h> 
#include "PrayerTimes.h" 
#include <SystemFont5x7.h> 
#include <angka6x13.h> 
#include <Droid_Sans_12.h> 
#include <SPI.h> 
 
  
DMD dmd(1, 1); //untuk mengatur jumlah panel  
 
double times[sizeof(TimeName) / sizeof(char*)]; 
void ScanDMD(){   dmd.scanDisplayBySPI();   } 

 
void setup() 
{ 
rtc.begin(); 
Wire.begin(); 
Timer1.initialize( 500 ); 
Timer1.attachInterrupt( ScanDMD ); 
dmd.clearScreen( true );  } 

 
void loop() 
{ 
DateTime now = rtc.now(); 
String Teks; 

int hours, minutes; 
long mulai = millis(); 

 
dmd.clearScreen( true ); 
int langkah=0; 

while (millis() - mulai < 20000) 
{ 
now = rtc.now(); 
String xjam = Konversi(now.hour()) ; //tampilan jam 
int pjg = xjam.length() + 1; 
char sjam[pjg]; 
xjam.toCharArray(sjam, pjg); 
dmd.selectFont(angka6x13); 
dmd.drawString(1, 1, sjam, pjg, 0); 
 
String xxjam =  Konversi(now.minute()) ; //tampilan menit 
int xpjg = xxjam.length() + 1; 
char xsjam[xpjg]; 
xxjam.toCharArray(xsjam, xpjg); 
dmd.selectFont(angka6x13); 
dmd.drawString(18, 1, xsjam, xpjg, 0); 
dmd.selectFont(SystemFont5x7); 

dmd.drawChar( 14,  4, ':', GRAPHICS_OR     );   // clock colon overlay on 
delay( 1000 ); 

dmd.drawChar( 14, 4, ':', GRAPHICS_NOR    );   // clock colon overlay off 
delay( 1000 ); 
} 
} 

 
String Konversi(int sInput) { 
if (sInput < 10) 
{ 
return"0" + String(sInput); 
} 
else 
{ 
return String(sInput); 
} 
} 
