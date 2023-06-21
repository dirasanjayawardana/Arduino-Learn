#include <AFMotor.h>
AF_DCMotor motor1 (1, MOTOR12_64KHZ);     //MOTOR 1 KECEPATAN MAKSIMAL 64KHZ
AF_DCMotor motor2 (2, MOTOR12_64KHZ);     //MOTOR 2 KECEPATAN MAKSIMAL 64KHZ
AF_DCMotor motor3 (3, MOTOR12_64KHZ);     //MOTOR 2 KECEPATAN MAKSIMAL 64KHZ
AF_DCMotor motor4 (4, MOTOR12_64KHZ);     //MOTOR 2 KECEPATAN MAKSIMAL 64KHZ
char cek;

void setup(){
  Serial.begin(9600);
 /* motor1.setSpeed(50);  // set kecepatan motor antara 0-255
    motor2.setSpeed(50);
    motor3.setSpeed(50);
    motor4.setSpeed(50); */
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    
}

void loop(){
  if (Serial.available()>0){
    cek = Serial.read();
    Serial.print(cek);
  }
  motorjalan();
  setkecepatan();
}

void setkecepatan(){
  if (cek == '2'){
    motor1.setSpeed(100);
    motor2.setSpeed(100);
    motor3.setSpeed(100);
    motor4.setSpeed(100);
  }
  if (cek == '4'){
    motor1.setSpeed(100);
    motor2.setSpeed(100);
    motor3.setSpeed(100);
    motor4.setSpeed(100);
  }
  if (cek == '6'){
    motor1.setSpeed(150);
    motor2.setSpeed(150);
    motor3.setSpeed(150);
    motor4.setSpeed(150);
  }
  if (cek == '8'){
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);
  }
  if (cek == 'q'){
    motor1.setSpeed(250);
    motor2.setSpeed(250);
    motor3.setSpeed(250);
    motor4.setSpeed(250);
  }
}

void motorjalan(){
  if (cek == 'S'){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  if (cek == 'B'){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  if (cek == 'F'){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  if (cek == 'L'){
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
  }
  if (cek == 'R'){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  }
  if (cek == 'H'){   //SERONG KIRI DEPAN
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(RELEASE);
  }
  if (cek == 'J'){    //SERONG KANAN DEPAN
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
  }
  if (cek == 'G'){    //SEONG KIRI BELAKANG
    motor1.run(RELEASE);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(RELEASE);
  }
  if (cek == 'I'){   //SERONG KANAN BELAKANG
    motor1.run(BACKWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(BACKWARD);
  }
}
