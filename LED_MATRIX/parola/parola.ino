#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

const uint16_t WAIT_TIME = 1000;

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;


MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  
  rtc.begin();
  P.begin();

}

void loop(void)
{
  DateTime now = rtc.now();
  int b = (now.second());
  String a = String(now.hour())+String(now.minute())+String(now.second());
  P.print(b);
  delay(WAIT_TIME);
}
