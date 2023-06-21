#include <RFID.h>
#include <SPI.h>

#define SS_PIN 10 //pin RFID yang bisa di ubah
#define RST_PIN 9 //pin RFID yang bisa di ubah

#include <dht.h>
#define DATA_PIN A0 // Definisi Pin untuk DHT22
dht DHT; // Buat DHT object

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

#define led 2

RFID rfid(SS_PIN,RST_PIN);

int serNum[5];

int cards[][5] = {
  {113, 103, 42, 8, 52} // alamat card 
  };
  
bool access = false;

void setup()
{
  lcd.begin(16, 2);
  SPI.begin();
  rfid.init();
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  nama(); //memanggil fungsi nama
}

void loop(){
  
int readData = DHT.read22(DATA_PIN); // baca Data dari sensor
float t = DHT.temperature; // Ambil nilai Suhu
float h = DHT.humidity; // Ambil nilai Kelembaban

    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
           
        }
        
       if(access){
          digitalWrite(led, HIGH);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Suhu: ");
          lcd.print(t);
          lcd.print(" C");
          lcd.setCursor(0,1);
          lcd.print("Humi: ");
          lcd.print(h);
          lcd.print(" %");
          delay(5000);
          nama();
          digitalWrite(led, LOW);

          } 
      
      else {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Password ditolak");
          delay(5000);
          nama();
          }        
    }
    
    rfid.halt();
}


void nama(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);
  lcd.print(" Scan Password");
}
