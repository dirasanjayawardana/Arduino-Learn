/*-------------------------------------------------------------------------------------------------
 * Project  : Jam Digital P10 32x16 Dengan Setting Tombol                  ///////
 * Author   : Irfan Indra Kurniawan                               /////////
 * Website  : www.FansElectronics.com                           ///////////
 * Copyright 2017 FansElectronics                           /////////////
 *                                          ///////////////
 * CHANGELOG                                      /////////////////
 * > 8 February 2017                                                            ///////////////////
 ------------------------------------------------------------------------------------------------*/
///////////////////////////////// Menyertakan File Library ////////////////////////////////////////
#include <SPI.h>                                                      // SPI Library
#include <TimerOne.h>                                                 // Timer1 Library
#include <DMD.h>                                                      // DMD Library
#include <RTClib.h>                                                   // Real Time Clock Library
#include <BigNumber.h>                                              // Font Libary
#include <System6x7.h>                                                // Font Libary

///////////////////////////////// Mendifinisikan Pin Tombol ////////////////////////////////////////
#define Fans_bUP 3                                                    // Tombol Atas
#define Fans_bOK 2                                                    // Tombol OK
#define Fans_bDN 4                                                    // Tombol Bawah

////////////////////////////////////// Setting Varible /////////////////////////////////////////////
int Fans_textSpeed = 100;
/////////////////////////////////////// Global Varible /////////////////////////////////////////////
int Fans_Hari,Fans_Tanggal,Fans_Bulan,Fans_Tahun,Fans_Jam,Fans_Menit,Fans_Detik;
int s,i,x;
char Fans_dmdBuff[10];
String Fans_sBuff;
double old;
boolean Fans_MiniTTK = false;
boolean Fans_BigTTK = false;
boolean Fans_Setting = false;

RTC_DS3231 Fans_RTC;
DMD Fans_DMD(1,1);

//////////////////////////////////////// Fungsi Setup //////////////////////////////////////////////
void setup() {
  Fans_RTC.begin();                                                   // Initialize RTC Modul
  Serial.begin(9600);                                                 // Initialize Komunikasi Serial
  Timer1.initialize(2000);                                            // Initialize Timer 1         
  Timer1.attachInterrupt(ScanDMD);                                    // Interrupts Timer 1 
  Fans_DMD.clearScreen(true);                                         // Hapus Tampilan P10
 
  pinMode(Fans_bOK,INPUT_PULLUP);                                     // Mode Pin Sebagai Input dengan Pull Up Internal
  pinMode(Fans_bUP,INPUT_PULLUP);                                     // Mode Pin Sebagai Input dengan Pull Up Internal
  pinMode(Fans_bDN,INPUT_PULLUP);                                     // Mode Pin Sebagai Input dengan Pull Up Internal
  
  attachInterrupt(0,Setting,FALLING);                                 // Intterupt Tombol Settingan

}

////////////////////////////////// Fungsi Looping/Pengulagan ///////////////////////////////////////
void loop() {
  if(Fans_Setting){MenuSetting();}                                    // Jika Tombol OK/Interrupt ditekan maka masuk menu setting Manual
  BigJam();                                                           // Baca Fungsi BigJam
}

////////////////////////////////////// Interrupt Timer 1 ///////////////////////////////////////////
void ScanDMD() {
  Fans_DMD.scanDisplayBySPI();                                        // Timer Scanning untuk P10
  if(Fans_MiniTTK){                                                   // Fungsi aktifkan Mini Titik pada interrupt
    if((millis() > (old+500))) {
      Fans_DMD.drawChar( 15, 0, ':', GRAPHICS_OR);
    }
    if((millis() < (old+1000)) && (millis()>(old+500))) {
      Fans_DMD.drawChar( 15, 0, ':', GRAPHICS_NOR); 
    }
    if(millis() > (old+1000) ) {old=millis();}  
  } 
  if(Fans_BigTTK){                                                    // Fungsi aktifkan Big Titik pada interrupt
    if((millis() > (old+500))) {
      Fans_DMD.drawFilledBox( 15, 4, 16, 5, GRAPHICS_OR );
      Fans_DMD.drawFilledBox( 15, 10, 16, 11, GRAPHICS_OR );
    }
    if(( millis() < (old+1000)) && (millis() > (old+500))) { 
      Fans_DMD.drawFilledBox( 15, 4, 16, 5, GRAPHICS_NOR );
      Fans_DMD.drawFilledBox( 15, 10, 16, 11, GRAPHICS_NOR );         
    }
    if(millis() > (old+1000) ) {
      old=millis();   
    }
  }
}

/////////////////////////////////// Interrupt Button Setting ////////////////////////////////////////
void Setting() {
  Fans_Setting = true;                                                // Aktifkan Menu Setting
}

//////////////////////////////////// Fungsi Tampil Jam Besar ////////////////////////////////////////
void BigJam() {                                                     
  DateTime now = Fans_RTC.now();                                      // Baca Data RTC Sekarang
  Fans_MiniTTK = false;                                               // Mini Titik Mati
  Fans_BigTTK = true;                                                 // Big Titik Aktif
  Fans_DMD.selectFont(BigNumber);                                     // Font Select "BigNumber"
  
  // Display JAM
  Fans_sBuff = Fans_Convert(now.hour());                              // Covert Int to String Jam
  s = Fans_sBuff.length()+1;                                          // Panjang Karakter String
  Fans_dmdBuff[s];                                                    // Deklarasi variable Array
  Fans_sBuff.toCharArray(Fans_dmdBuff,s);                             // Conver String to Char Array
  Fans_DMD.drawString(1,0,Fans_dmdBuff,s,0);                          // Tampilkan Nilai Char Array pada P10
  
  // Display Menit
  Fans_sBuff = Fans_Convert(now.minute());                            // Covert Int to String Menit
  s = Fans_sBuff.length()+1;                                          // Panjang Karakter String
  Fans_dmdBuff[s];                                                    // Deklarasi variable Array
  Fans_sBuff.toCharArray(Fans_dmdBuff,s);                             // Conver String to Char Array
  Fans_DMD.drawString(18,0,Fans_dmdBuff,s,0);                         // Tampilkan Nilai Char Array pada P10
}
////////////////////////////////////// Fungsi Menu Setting //////////////////////////////////////////
void MenuSetting() {
  DateTime now = Fans_RTC.now();                                      // Baca Data RTC Sekarang
  Fans_Tanggal = now.day();                                           // Singkron Variable Tanggal dengan RTC
  Fans_Bulan = now.month();                                           // Singkron Variable Bulan dengan RTC
  Fans_Tahun = now.year();                                            // Singkron Variable Tahun dengan RTC
  Fans_Jam = now.hour();                                              // Singkron Variable Jam dengan RTC
  Fans_Menit = now.minute();                                          // Singkron Variable Menit dengan RTC
  Fans_MiniTTK = false;                                               // Mini Titik Mati
  Fans_BigTTK = false;                                                // Big Titik Mati
  Fans_DMD.selectFont(System6x7);                                     // Font Select "BigNumber"
  Fans_DMD.clearScreen(true);                                         // Hapus Tampilan P10
  detachInterrupt(0);                                                 // Matikan interrupt "0"
  delay(500);                                                         // Delay 500ms

/////////////////////////////////////// Setting Jam & Menit //////////////////////////////////////////
  setTimes:                                                           // Setting Times (Jam & Menit)
    if(digitalRead(Fans_bUP) == LOW) {                                // Tombol Setting Menit
      delay(10); Fans_Menit++;                                        // Delay Tombol & Tambah Nilai Menit
      if(Fans_Menit >= 60){Fans_Menit = 0;}                           // Batas Nilai Menit Lebih dari 59 Kembali ke 0
      while(digitalRead(Fans_bUP) == LOW) {}                          // Kunci Tombol Setting Menit Sampai Lepas Tombol
    }
    if(digitalRead(Fans_bDN) == LOW) {                                // Tombol Setting Menit
      delay(10); Fans_Jam++;                                          // Delay Tombol & Tambah Nilai Jam
      if(Fans_Jam >= 24){Fans_Jam = 0;}                               // Batas Nilai Jam Lebih dari 23 Kembali ke 0
      while(digitalRead(Fans_bDN) == LOW) {}                          // Kunci Tombol Setting Jam Sampai Lepas Tombol
    }

    if(digitalRead(Fans_bOK) == LOW) {                                // Tombol Selesai Setting
      Fans_DMD.clearScreen(true);                                     // Hapus Tampilan P10
      Fans_RTC.adjust(DateTime(now.year(), now.month(), now.day(),    // Setting Nilai RTC Module
                      Fans_Jam, Fans_Menit, now.second()));
      while(digitalRead(Fans_bOK) == LOW) {}                          // Kunci Tombol OK Sampai Lepas Tombol
      delay(500);                                                     // Delay Tombol                                           
      goto endSetting;                                                // Pergi ke Label setTglBln
    }
    
    Fans_DMD.drawString(3,0,"TIME",4,0);                              // Tampilkan String "TIME" Pada P10
    Fans_DMD.drawChar( 15, 8, ':', GRAPHICS_OR);                      // Tampilkan Char ':' Pada P10
    // Display JAM
    Fans_sBuff = Fans_Convert(Fans_Jam);                              // Covert Int to String Jam
    s = Fans_sBuff.length()+1;                                        // Panjang Karakter String
    Fans_dmdBuff[s];                                                  // Deklarasi variable Array
    Fans_sBuff.toCharArray(Fans_dmdBuff,s);                           // Conver String to Char Array
    Fans_DMD.drawString(1,8,Fans_dmdBuff,s,0);                        // Tampilkan Nilai Char Array pada P10
  
    // Display Menit
    Fans_sBuff = Fans_Convert(Fans_Menit);                            // Covert Int to String Menit
    s = Fans_sBuff.length()+1;                                        // Panjang Karakter String
    Fans_dmdBuff[s];                                                  // Deklarasi variable Array
    Fans_sBuff.toCharArray(Fans_dmdBuff,s);                           // Conver String to Char Array
    Fans_DMD.drawString(18,8,Fans_dmdBuff,s,0);                       // Tampilkan Nilai Char Array pada P10
  goto setTimes;                                                      // Pergi ke Label setTimes
  
  endSetting:                                                         // Label End Setting                                                         
  attachInterrupt(0,Setting,FALLING);                                 // Interrupt Tombol OK
  Fans_Setting = false;                                               // Akhiri Setting Menu
}

///////////////////////////////////// Fungsi Convert 2 Digit  ///////////////////////////////////////
String Fans_Convert(int Num){                                         // Variable String Convert nilai Int
  if(Num < 10){                                                       // Jika Num kurang dari 10
    return "0"+String(Num);                                           // Tambahkan Angka '0' diawal variable, dan convert String
  }
  else{                                                               // Jika Num lebih dari 10
    return String(Num);                                               // Convert String
  }
}
