#include <Keypad.h>
#include <plcLib.h>

char keyPress = 0;
const byte ROWS = 4;
const byte COLS = 4;
int led = 6
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8, 19 }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  setupPLC();
  Serial.begin(9600);
}

void loop()
{
  keyPress = kpd.getKey();    // Read key pressed (if any)
  
  latchKey('1', '2', Y0);     // Keyboard latch, Set = '1', Reset = '2',
                              // output = Y0 (pin 3)
  
  latchKey('3', '4', Y1);     // Keyboard latch, Set = '3', Reset = '4',
                              // output = Y1 (pin 5)
  
  latchKey('5', '6', Y2);     // Keyboard latch, Set = '5', Reset = '6',
                              // output = Y2 (pin 6)
  
  latchKey('7', '8', Y3);     // Keyboard latch, Set = '7', Reset = '8',
                              // output = Y3 (pin 9)
}

unsigned int latchKey(char en, char dis, int outPin) {
  if(keyPress) {
    if (keyPress == en) {
      digitalWrite(led, HIGH);
      Serial.println("Lampu Menyala");
    }
    if (keyPress == dis) {
      digitalWrite(led, LOW);
      Serial.println("Lampu Mati");
    }
  } 
}
} 
