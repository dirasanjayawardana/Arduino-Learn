const int pinRelay1 = 11;
const int pinRelay2 = 10;
const int pinRelay3 = 9;
const int pinRelay4 = 8;

int relay_ON = 1;
int relay_OFF = 0;

char val;

void setup() {
  Serial.begin(9600);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
  pinMode(pinRelay3, OUTPUT);
  pinMode(pinRelay4, OUTPUT);
 
  digitalWrite(pinRelay1, relay_OFF);
  digitalWrite(pinRelay2, relay_OFF);
  digitalWrite(pinRelay3, relay_OFF);
  digitalWrite(pinRelay4, relay_OFF);
}

void loop() {
  if(Serial.available() > 0){
    val = Serial.read();
    
    if(val == 'a'){
      digitalWrite(pinRelay1, relay_ON);
    }else if(val == 'b'){
      digitalWrite(pinRelay2, relay_ON);
    }else if(val == 'c'){
      digitalWrite(pinRelay3, relay_ON);
    }else if( val == 'd'){
      digitalWrite(pinRelay4, relay_ON);
    }else if(val == 'A'){
      digitalWrite(pinRelay1, relay_OFF); 
    }else if( val == 'B'){
      digitalWrite(pinRelay2, relay_OFF);
    }else if( val == 'C'){
      digitalWrite(pinRelay3, relay_OFF);
    }else if( val == 'D'){
      digitalWrite(pinRelay4, relay_OFF);
    }
  }
}
