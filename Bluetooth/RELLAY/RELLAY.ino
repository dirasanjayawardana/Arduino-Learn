#define relay1 2
#define relay2 3

char data;

void setup(){
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void loop(){
  if(Serial.available()>0){
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    
  if(data== '1'){
    digitalWrite(relay1, HIGH);
    
  }else if(data== '2'){
    digitalWrite(relay1, LOW);
    
  }else if(data== '3'){
    digitalWrite(relay2, HIGH);

  }else if(data== '4'){
    digitalWrite(relay2, LOW);
  }
  }
}
