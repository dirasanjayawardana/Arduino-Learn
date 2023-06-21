#include "LedControl.h"
LedControl lc=LedControl(2,3,4,4); 

#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

//----Time Var----------
int TimeHours10s;
int TimeHours1s;
int TimeMinutes10s;
int TimeMinutes1s;
int TimeSeconds10s;
int TimeSeconds1s;
//----------------------

//---Input Pins for setting  Time--

//---------------------------------
void setup() 
{
  // initialize I/O pins----------------------------
  rtc.begin();
  Serial.begin(9600);
  Wire.begin();

  if (! rtc.isrunning())
  {
  Serial.println("RTC is Not running");
  }
  
  //-----------------------------------------------
   lc.shutdown(0,false);
    lc.shutdown(1,false);
    lc.shutdown(2,false);
    lc.shutdown(3,false);
   //set a medium brightness for the Leds
   lc.setIntensity(0,2);
   lc.setIntensity(1,2);
   lc.setIntensity(2,2);
   lc.setIntensity(3,2); 
}

void loop() 
{
ShowTime();
delay(965);
//---------------------------------
  }




void SendDataDotMatrix(int DispNumber,int Digit)
{
int dp;
if(Digit == 1)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;
 //-----------------Show 1----------------------
lc.setRow(DispNumber,0,0x10 );
lc.setRow(DispNumber,1,0x30 );
lc.setRow(DispNumber,2,0x10 | dp);
lc.setRow(DispNumber,3,0x10 );
lc.setRow(DispNumber,4,0x10 );
lc.setRow(DispNumber,5,0x10 | dp);
lc.setRow(DispNumber,6,0x10 );
lc.setRow(DispNumber,7,0x00 );
//---------------------------------------------
}
if(Digit == 2)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;
//-----------------Show 2----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x04);
lc.setRow(DispNumber,2,0x04 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x40);
lc.setRow(DispNumber,5,0x40 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 3)
{
   if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;
//-----------------Show 3----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x04);
lc.setRow(DispNumber,2,0x04 | dp);
lc.setRow(DispNumber,3,0x3c);
lc.setRow(DispNumber,4,0x04);
lc.setRow(DispNumber,5,0x04 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}
 
//---------------------------------------------
if(Digit == 4)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;
//-----------------Show 4----------------------
lc.setRow(DispNumber,0,0x44);
lc.setRow(DispNumber,1,0x44);
lc.setRow(DispNumber,2,0x44 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x04);
lc.setRow(DispNumber,5,0x04 | dp);
lc.setRow(DispNumber,6,0x04);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 5)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;
//-----------------Show 5----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x40);
lc.setRow(DispNumber,2,0x40 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x04);
lc.setRow(DispNumber,5,0x04 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 6)
{
if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;  
//-----------------Show 6----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x40);
lc.setRow(DispNumber,2,0x40 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x44);
lc.setRow(DispNumber,5,0x44 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}

//---------------------------------------------
if(Digit == 7)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;  
//-----------------Show 7----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x04);
lc.setRow(DispNumber,2,0x04 | dp);
lc.setRow(DispNumber,3,0x08);
lc.setRow(DispNumber,4,0x10);
lc.setRow(DispNumber,5,0x10 | dp);
lc.setRow(DispNumber,6,0x10);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 8)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;  
//-----------------Show 8----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x44);
lc.setRow(DispNumber,2,0x44 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x44);
lc.setRow(DispNumber,5,0x44 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 9)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;  
//-----------------Show 9----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x44);
lc.setRow(DispNumber,2,0x44 | dp);
lc.setRow(DispNumber,3,0x7c);
lc.setRow(DispNumber,4,0x04);
lc.setRow(DispNumber,5,0x04 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}
//---------------------------------------------
if(Digit == 0)
{
  if(DispNumber == 2)//
  dp = 0x01;
  else
  dp = 0x00;  
//-----------------Show 0----------------------
lc.setRow(DispNumber,0,0x7c);
lc.setRow(DispNumber,1,0x44);
lc.setRow(DispNumber,2,0x44 | dp);
lc.setRow(DispNumber,3,0x44);
lc.setRow(DispNumber,4,0x44);
lc.setRow(DispNumber,5,0x44 | dp);
lc.setRow(DispNumber,6,0x7c);
lc.setRow(DispNumber,7,0x00);
}

}


void ShowTime()
  {
    if (! rtc.isrunning()){
       SendDataDotMatrix(0,1);
       SendDataDotMatrix(1,1);
       SendDataDotMatrix(2,1);
       SendDataDotMatrix(3,1);
    }

//-------------------------------------------------
DateTime now = rtc.now();

if (now.minute()>=0 && now.minute()<=9){
  TimeMinutes1s = now.minute();
  TimeMinutes10s = 0;
} 
     
if (now.minute()>=10 && now.minute()<=19){
  TimeMinutes1s = now.minute()-10;
  TimeMinutes10s = 1;
}
if (now.minute()>=20 && now.minute()<=29){
  TimeMinutes1s = now.minute()-20;
  TimeMinutes10s = 2;
}
if (now.minute()>=30 && now.minute()<=39){
  TimeMinutes1s = now.minute()-30;
  TimeMinutes10s = 3;
}
if (now.minute()>=40 && now.minute()<=49){
  TimeMinutes1s = now.minute()-40;
  TimeMinutes10s = 4;
}
if (now.minute()>=50 && now.minute()<=59){
  TimeMinutes1s = now.minute()-50;
  TimeMinutes10s = 5;
}
//--------------------------------------------
if (now.hour()>=0 && now.hour()<=9){
  TimeHours1s = now.hour();
  TimeHours10s = 0;
}
if (now.hour()>=10 && now.hour()<=19){
  TimeHours1s = now.hour()-10;
  TimeHours10s = 1;
}
if (now.hour()>=20 && now.hour()<=23){
  TimeHours1s = now.hour()-20;
  TimeHours10s = 2;
}

 //--------------------------------------------
 SendDataDotMatrix(0,TimeMinutes1s);
 SendDataDotMatrix(1,TimeMinutes10s);

 SendDataDotMatrix(2,TimeHours1s);
 if(TimeHours10s == 0)
 lc.shutdown(3,true);
 else
 {
  lc.shutdown(3,false);
 SendDataDotMatrix(3,TimeHours10s);
 }

 //--------------------------------------------- 

 }
