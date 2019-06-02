#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int temp; //variable to hold temperature sensor value
long tm,t,d; //variables to record time in seconds
#define analogPin A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor
void setup()

{
  Serial.begin(9600);
  pinMode(0,INPUT);//temperature sensor connected to analog 0
  analogReference(DEFAULT);
}

void loop()
{
  long a =1023 - analogRead(analogPin); //read thermistor value
  
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0 + 43.5;
  //required for converting time to seconds
  tm = millis();
  t = tm/1000;
  d = tm%1000;

  Serial.flush();

  //printing time in seconds
  Serial.print("time : ");
  Serial.print(t);
  Serial.print(".");
  Serial.print(d);
  Serial.print("s\t");

  //printing temperature sensor values
  Serial.print("temperature : ");
  Serial.print(tempC);
  Serial.println("C");
  
  delay(2000);//delay of 2 seconds
}
