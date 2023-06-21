#include <Keypad.h>
int led1=10;
int led2=11;
int led3=A4;

const byte baris= 4; //baris pada keypad
const byte kolom= 4; //Kolom pada keypad
byte pinbaris[baris]= {2,3,4,5};    //letak pin baris pada arduino
byte pinkolom[kolom]= {6,7,8,9};    //letak pin baris pada arduino

/*keymap mendefinisikan tombol ditekan sesuai
dengan baris dan kolom seperti muncul pada keypad*/
char keymap[baris][kolom]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


Keypad myKeypad= Keypad(makeKeymap(keymap), pinbaris, pinkolom, baris, kolom);

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

// Jika tombol ditekan, tombol ini disimpan dalam 'keypressed' variabel
// Jika kunci tidak sama dengan 'NO_KEY', maka tombol ini dicetak
// Jika jumlah = 17, maka penghitungan reset kembali ke 0 (ini berarti tidak ada tombol yang ditekan selama proses pemindaian seluruh keypad

void loop(){

char keypressed = myKeypad.getKey();


if (keypressed == '1'){
  digitalWrite(led1,HIGH);
  Serial.print(keypressed);}
  
if (keypressed == '2'){
  digitalWrite(led1,LOW);
  Serial.print(keypressed);}

if (keypressed == '3'){
  digitalWrite(led2,HIGH);
  Serial.print(keypressed);}

if (keypressed == '4'){
  digitalWrite(led2,LOW);
  Serial.print(keypressed);}

if (keypressed == '5'){
  digitalWrite(led3,HIGH);
  Serial.print(keypressed);}

if (keypressed == '6'){
  digitalWrite(led3,LOW);
  Serial.print(keypressed);}
}
