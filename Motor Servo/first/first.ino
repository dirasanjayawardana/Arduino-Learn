#include <Servo.h>
Servo servo1;
void setup() {
  servo1.attach(A0); // set pin servio pada arduino (bisa pin analog atau digital)

}

void loop() {
  servo1.write(0); // set servo berputar 0 derajat
  delay(1000);
  servo1.write(90); // set servo berputar 90 derajat
  delay(1000);
  servo1.write(180);  // set servo berputar 180 derajat
  delay(1000);
  servo1.write(90); // set servo berputar 90 derajat
  delay(1000);
}
