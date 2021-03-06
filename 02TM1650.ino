#include <Wire.h>
#include <TM1650.h>

TM1650 d;

void setup() 
{
  Wire.begin(); //Join the bus as master

  Serial.begin(38400); //Start serial communication at 9600 for debug statements
  Serial.println("TM1650 Example Code");

  d.init();
   
}

void loop() 
{
  d.displayOff();
  d.displayString("____");
  d.setBrightness(TM1650_MIN_BRIGHT);
  d.displayOn();
  delay(100);
  char line[] = "1234";

  d.displayString(line);
  d.setBrightnessGradually(TM1650_MAX_BRIGHT);
  delay(2000);
  d.setBrightnessGradually(TM1650_MIN_BRIGHT);
  d.displayOff();
  delay(1000);
  
  line[1] |= 128;
  d.displayOn();
  d.setBrightnessGradually(TM1650_MAX_BRIGHT);
  d.displayString(line);
  delay(2000);
  
//  for (int i=0; i<8; i++) {
//    d.setBrightness(i);
//    delay(500);
//  }
  
  d.displayString("abcd");
  delay(2000);

  d.displayString("1234");
  delay(2000);
  
  if (d.displayRunning("1234567890abcdefg")) {
    while (d.displayRunningShift()) delay(500);
  }
  delay(2000);
  
  }

  
