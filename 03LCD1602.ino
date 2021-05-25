//sketch created by Akshay Joseph
#include <Wire.h> 
#include <DFRobot_LiquidCrystal_I2C.h>

DFRobot_LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

  lcd.init();
  lcd.begin(16, 2);


  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("hello! code!");
}

void loop()
{
}
