
#include <dht.h>
#define DATA_PIN A0 // Definisi Pin untuk DHT22
dht DHT; // Buat DHT object

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

#define relay1 2
#define relay2 3
#define relay3 4
#define relay4 5

char data;

void setup(){

  lcd.begin(16, 2);
  Serial.begin(9600);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);

  nama();
}

void loop(){
  
  int readData = DHT.read22(DATA_PIN); // baca Data dari sensor
  float t = DHT.temperature; // Ambil nilai Suhu
  float h = DHT.humidity; // Ambil nilai Kelembaban

  if(Serial.available()>0){
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    
  if(data== '1'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Suhu : ");
    lcd.print(t);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Humi : ");
    lcd.print(h);
    lcd.print(" %");
    delay(5000);
    nama(); 
      
  }else if(data== '2'){
    menu();
    
  }else if(data== '3'){
    digitalWrite(relay1, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay1 ON");
    delay(2000);
    nama();

  }else if(data== '4'){
    digitalWrite(relay1, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay1 OFF");
    delay(2000);
    nama();
    
  }else if(data== '5'){
    digitalWrite(relay2, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay2 ON");
    delay(2000);
    nama();

  }else if(data== '6'){
    digitalWrite(relay2, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay2 OFF");
    delay(2000);
    nama();

  }else if(data== '7'){
    digitalWrite(relay3, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay3 ON");
    delay(2000);
    nama();

  }else if(data== '8'){
    digitalWrite(relay3, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay3 OFF");
    delay(2000);
    nama();

  }else if(data== '9'){
    digitalWrite(relay4, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay4 ON");
    delay(2000);
    nama();

  }else if(data== 'A'){
    digitalWrite(relay4, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Relay4 OFF");
    delay(2000);
    nama();
  }
  }
}

void nama(){
  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);
  lcd.print("Bluetooth Conect");
}

void menu (){
  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("1. Suhu & kelemb");
  lcd.setCursor(0,1);
  lcd.print("2. Relay1 ON");
  delay(1000);

  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("3. Relay2 ON");
  lcd.setCursor(0,1);
  lcd.print("4. Relay3 ON");
  delay(1000);

  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("5. Relay4 ON");
  lcd.setCursor(0,1);
  lcd.print("4. Relay5 ON");
  delay(1000);
  

  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);
  lcd.print("Bluetooth Conect");
}
