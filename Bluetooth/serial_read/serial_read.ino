#include <Wire.h>
char a;

void setup() {
  Serial.begin(9600);

}

void loop() {
if (Serial.available()>0){
  a = Serial.read();
  Serial.println(a);

}}
