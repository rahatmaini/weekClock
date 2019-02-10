#include <Servo.h>
Servo spinnyBoi;
int flexSensorPin = A0;


void setup()
{
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()
{ 
  

  if (Serial.available()) {
    light(Serial.read()-'0');
  }

  /*
  if (digitalRead(firstWire)==LOW && digitalRead(secondWire)==LOW)
    //light up blue, rain

  if (digitalRead(firstWire)==HIGH && digitalRead(secondWire)==HIGH)
    //light up red, over 90

  if (digitalRead(firstWire)==LOW && digitalRead(secondWire)==HIGH)
    //light up green, mail

  if (digitalRead(firstWire)==HIGH && digitalRead(secondWire)==LOW)
    //turn off light
  */

  delay(50); 
}

void light(int x)
{
  if (x==0) //rain
  {
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  }
  if (x==1) //over 90 
  {
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  }
  if (x==2) //mailroom
  {
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  }
  if (x==3) //reset
  {
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  }
  if (x==4)
  {
  while (1)
    {
      Serial.println(analogRead(flexSensorPin));
      spinnyBoi.attach(11);
    if (analogRead(flexSensorPin)<19)
    {
      
      delay(250);
      spinnyBoi.detach();
      break;
    }
    }
  }
    

}
