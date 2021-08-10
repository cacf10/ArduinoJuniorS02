//sketch created by Akshay Joseph
#include <Wire.h> 
#include <DFRobot_LiquidCrystal_I2C.h>

DFRobot_LiquidCrystal_I2C lcd(0x27, 16, 2);


int Vin=5;        //voltage at 5V pin of arduino
float Vout=0;     //voltage at A0 pin of arduino
float R1=4700;    //value of known resistance
float R2=0;       //value of unknown resistance
int a2d_data=0;    
float buffer=0;            

void setup() 
{
  lcd.init();
  lcd.begin(16,2);

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("ohm meter");
}

void loop()
{
  a2d_data=analogRead(A0);
  if(a2d_data)
  {
    buffer=a2d_data*Vin;
    Vout=(buffer)/1024.0;
    buffer=Vout/(Vin-Vout); 
    R2=R1*buffer;

    lcd.setCursor(0,1);
    lcd.print("R = ");
    lcd.print(R2);
    
    delay(1000);
  }
}
