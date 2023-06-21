#define l1 2
#define l2 3
#define l3 4
#define e 6
#define t 7
double pulsa = 0;

void setup() {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(e, INPUT);
  pinMode(t, OUTPUT);
}

void loop() {
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  pulsa = pulseIn(e, HIGH);
  int p;
  p = round(pulsa / 58.26);
  if (p<=10){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }
   else if (p<=30){
   digitalWrite(l1, LOW);
   digitalWrite(l2, HIGH);
   digitalWrite(l3, LOW);
  }
  else if (p<=50){
   digitalWrite(l1, LOW);
   digitalWrite(l2, LOW);
   digitalWrite(l3, HIGH);
  }
    else {
   digitalWrite(l1, LOW);
   digitalWrite(l2, LOW);
   digitalWrite(l3, LOW);
  }
  
  
}
