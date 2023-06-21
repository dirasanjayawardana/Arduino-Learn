//mencari alamat i2c

#include <Wire.h>
void setup() {
Serial.begin (115200);
while (!Serial)
{
}


Serial.println ();
Serial.println ("Scanni");
byte count = 0;
Wire.begin();
for (byte i = 1; i < 120; i++)
{
Wire.beginTransmission (i);


if (Wire.endTransmission () == 0)
{
Serial.print ("Alamat: ");
Serial.print (i, DEC);
Serial.print (" (0x");
Serial.print (i, HEX);
Serial.println (")");
count++;
delay (1);
}
}
Serial.println ("Done");
}
void loop()
{
}
