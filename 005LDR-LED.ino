

int Vin=5;        //voltage at 5V pin of arduino
float Vout=0;     //voltage at A0 pin of arduino
float R1=4700;    //value of known resistance
float R2=0;       //value of unknown resistance
int a2d_data=0;    
float buffer=0;            

void setup() 
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop()
{
  a2d_data=analogRead(A0);
  if(a2d_data)
  {
    buffer=a2d_data/4;
    analogWrite(3, buffer);

    Serial.println(buffer);

    
    
    delay(30);
  }
}
