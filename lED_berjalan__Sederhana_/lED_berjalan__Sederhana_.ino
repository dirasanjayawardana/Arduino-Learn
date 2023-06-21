void setup() {
  for (int i=2; i<8; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
   for(int i=2; i<8; i++){
   digitalWrite(i, HIGH);
   }delay(500);  //led hidup semua dengan delay 0,2 s

   for(int i=2; i<8; i++){
   digitalWrite(i, LOW);
   delay(200);  // led mati setu persatu
   }
   
   for(int i=2; i<8; i++){
   digitalWrite(i, HIGH);
   delay(200);
   digitalWrite(i, LOW);     // led berjalan
  }
   for(int i=2; i<8; i++){
   digitalWrite(i, HIGH);
   delay(200);             // led hidup satu persatu
   } 
   
}
