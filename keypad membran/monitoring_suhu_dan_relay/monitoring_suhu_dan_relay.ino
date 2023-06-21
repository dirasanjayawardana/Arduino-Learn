#include <dht.h>
#include <LiquidCrystal.h> 
#define DATA_PIN A0 // Definisi Pin untuk DHT22

int Contrast=90;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
dht DHT; // Buat DHT object

#include <Keypad.h>
const byte numRows= 4; //baris pada keypad
const byte numCols= 4; //Kolom pada keypad
int relay1= 8;
int relay2= 9;


/*keymap mendefinisikan tombol ditekan sesuai
dengan baris dan kolom seperti muncul pada keypad*/
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


byte rowPins[numRows]= {A5, A4, A3, A2}; 
byte colPins[numCols]= {A1, 11, 12, 13}; 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  analogWrite(10,Contrast);
  lcd.begin(16, 2);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Serial.begin(9600);

  nama(); //memanggil fungsi nama
}

// Jika tombol ditekan, tombol ini disimpan dalam 'keypressed' variabel
// Jika kunci tidak sama dengan 'NO_KEY', maka tombol ini dicetak
// Jika jumlah = 17, maka penghitungan reset kembali ke 0 (ini berarti tidak ada tombol yang ditekan selama proses pemindaian seluruh keypad

void loop(){
  
int readData = DHT.read22(DATA_PIN); // baca Data dari sensor
float t = DHT.temperature; // Ambil nilai Suhu
float h = DHT.humidity; // Ambil nilai Kelembaban

char keypressed = myKeypad.getKey();

if (keypressed == 'A'){
   home ();} //memanggil fungsi home

if (keypressed == '1'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Humi: ");
    lcd.print(h);
    lcd.print(" %");
    delay(5000);
    nama();
    }

if (keypressed == '2'){
    lcd.clear();
    digitalWrite(relay1, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Relay1 ON");
    delay(2000);
    nama();
    }

if (keypressed == '3'){
    lcd.clear();
    digitalWrite(relay1, LOW);
    lcd.setCursor(0,0);
    lcd.print("Relay1 OFF");
    delay(2000);
    nama();
    }

if (keypressed == '4'){
    lcd.clear();
    digitalWrite(relay2, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Relay2 ON");
    delay(2000);
    nama();
    }

if (keypressed == '5'){
    lcd.clear();
    digitalWrite(relay2, LOW);
    lcd.setCursor(0,0);
    lcd.print("Relay2 OFF");
    delay(2000);
    nama();
    }
    
}


//menggunakan fungsi
void home (){
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
  lcd.print("3. Relay1 OFF");
  lcd.setCursor(0,1);
  lcd.print("4. Relay2 ON");
  delay(1000);

  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("3. Relay2 OFF");
  delay(1000);

  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);
  lcd.print("    Tekan A");
}

void nama(){
  lcd.clear();
  delay(500);
  lcd.setCursor(0,0);
  lcd.print(" Dira Sanjaya W");
  lcd.setCursor(0,1);
  lcd.print("    Tekan A");
}
