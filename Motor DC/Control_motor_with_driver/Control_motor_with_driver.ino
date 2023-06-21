#include <AFMotor.h>
AF_DCMotor motor1 (1, MOTOR12_1KHZ);     //MOTOR 1 KECEPATAN MAKSIMAL 1KHZ
AF_DCMotor motor2 (2, MOTOR12_1KHZ);     //MOTOR 2 KECEPATAN MAKSIMAL 1KHZ
char cek;

void setup(){
  motor1.setSpeed(200);     //rentang kecepatan antar 0-255
  motor2.setSpeed(200);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()>0){
    cek = Serial.read();
    Serial.print(cek);
  }
  if (cek == 'S'){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }
  if (cek == 'F'){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  if (cek == 'B'){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  }
  
}
