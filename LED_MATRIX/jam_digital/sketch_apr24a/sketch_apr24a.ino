#include "LedControl.h"
LedControl lc=LedControl(2,3,4,4); 

//----Time Var----------
int TimeHours10s =  0;
int TimeHours1s = 0;
int TimeMinutes10s = 0;
int TimeMinutes1s =  0;
int TimeSeconds10s =  0;
int TimeSeconds1s =  0;
//----------------------

//---Input Pins for setting  Time--
int Min10 = 7;
int Hour10 = 5;
int Min = 8;
int Hour = 6;
int Buzzer =10;
//---------------------------------
void setup() 
{
  // initialize I/O pins----------------------------

  pinMode(Hour10, INPUT_PULLUP);     //Bit_8
  pinMode(Min10, INPUT_PULLUP);      //Bit_9
  pinMode(Hour, INPUT_PULLUP);     //Bit_8
  pinMode(Min, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);         //Bit_10
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
CalculateTime();  
ShowTime();
delay(963);
//-------------------------------------Adj Time Value--------------
if(digitalRead(Min10)== LOW)
{
  TimeMinutes10s++;
  //delay(500);
  CalculateTime();
  if (TimeMinutes10s >=6){
    TimeMinutes10s =0;
  }
}
if(digitalRead(Hour10)== LOW)
{
  TimeHours10s++;
  //delay(500);
  CalculateTime();
  if (TimeHours10s >2){
    TimeHours10s = 0;
  }
}
if(digitalRead(Min)== LOW)
{
  TimeMinutes1s++;
  //delay(500);
  CalculateTime();
}
if(digitalRead(Hour)== LOW)
{
  TimeHours1s++;
  //delay(500);
  CalculateTime();
}
//------------------------------------------------------------------
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


void CalculateTime()
{
 TimeSeconds1s++;
  if(TimeSeconds1s == 10)
  {
  TimeSeconds1s = 0;
  TimeSeconds10s++;
  }
  if(TimeSeconds10s == 6)
  {
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeMinutes1s++;
  }
  if(TimeMinutes1s == 10)
  {
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeMinutes10s++;
  }
  if(TimeMinutes10s == 6)
  {
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeHours1s++;
  }
  if(TimeHours1s == 10) 
  {
  TimeHours1s=0;
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeHours10s++;
  }
  if(TimeHours10s == 2 && TimeHours1s == 4) 
  {
  TimeHours10s=0; 
  TimeHours1s=0;
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
 
  } 
}
