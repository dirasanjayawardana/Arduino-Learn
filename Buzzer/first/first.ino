const int buzzer = 3;

void setup(){
}

void loop(){
  /*dasar-----------------------------------
  tone (buzzer, 500);
  delay(300);
  tone (buzzer, 0);      untuk mematikan buzer
  delay (300);
  digitalWrite(buzzer, LOW);     untuk mematikan buzzer         
  ---------------------------------------------*/
  
 for (int i=0; i<=2000; i+=100){
  tone(buzzer, i);
  delay(200);
 }
 for (int j=2000; j>=0; j-=100){
  tone (buzzer, j);
  delay(200);
 }

}
