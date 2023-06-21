#define digital 10
#define analog 11
#define maksimum 255
#define Tinggi 3
#define Rendah 2

void setup()
{
  Serial.begin(9600);
  Serial.flush();
}

void loop()
{
  Serial.flush();
  
  int perintah = 0;
  int nomor = 0;
  int value = 0;
  
  if (Serial.available() < 1) return;
  
  perintah = Serial.parseInt();
  nomor = Serial.parseInt();
  value = Serial.parseInt();
  
  if (perintah == digital)
  {
    if (value == Rendah) value = LOW;
    else if (value == Tinggi) value = HIGH;
    else return;
    set_digitalwrite (nomor, value);
    return;
  }
  
  if (perintah == analog)
  {
    analogWrite (nomor, value);
    return;
  }
}

void set_digitalwrite(int nomor, int value)
  {
    switch (nomor) 
    {
    case 13:
      pinMode(13, OUTPUT);
      digitalWrite(13, value);  
      break;
    
    case 12:
      pinMode(12, OUTPUT);
      digitalWrite(12, value);   
      break;
    
    case 11:
      pinMode(11, OUTPUT);
      digitalWrite(11, value);         
      break;
    
    case 10:
      pinMode(10, OUTPUT);
      digitalWrite(10, value);         
      break;
    
    case 9:
      pinMode(9, OUTPUT);
      digitalWrite(9, value);         
      break;
    
    case 8:
      pinMode(8, OUTPUT);
      digitalWrite(8, value);         
      break;

    case 7:
      pinMode(7, OUTPUT);
      digitalWrite(7, value);         
      break;
      
    case 6:
      pinMode(6, OUTPUT);
      digitalWrite(6, value);         
      break;
  
    case 5:
      pinMode(5, OUTPUT);
      digitalWrite(5, value); 
      break;
  
    case 4:
      pinMode(4, OUTPUT);
      digitalWrite(4, value);         
      break;
  
    case 3:
      pinMode(3, OUTPUT);
      digitalWrite(3, value);         
      break;
  
    case 2:
      pinMode(2, OUTPUT);
      digitalWrite(2, value); 
      break;      
    }
}    
