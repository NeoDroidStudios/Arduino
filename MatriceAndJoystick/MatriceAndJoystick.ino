// JOYSTICK
int X_pin;
int Y_pin;
const int SW_pin = 2;
// MATRICE
#include "LedControl.h"
LedControl lc=LedControl(12,10,11,1);

void setup() {
  Serial.begin(9600);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH); 
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  // JOYSTICK
  X_pin = analogRead(A0);
  Y_pin = analogRead(A1);
  int switchB = digitalRead(SW_pin);
  // MATRICE
  char x_translate = map(X_pin, 0,1023, 0, 7);
  char y_translate = map(Y_pin, 0,1023, 7, 0);

  Serial.print("Switch : ");
  Serial.print(switchB, DEC);
  Serial.print(" X_pin : ");
  Serial.print(X_pin, DEC);
  Serial.print(" Y_pin : ");
  Serial.print(Y_pin, DEC);
  Serial.print(" x : ");
  Serial.print(x_translate, DEC); 
  Serial.print(" y : ");
  Serial.println(y_translate, DEC); 
  
  lc.clearDisplay(0);
  lc.setLed(0,x_translate,y_translate,true);  

  if (switchB==1)
  {
    lc.setLed(0,x_translate,y_translate,true); 
  }
  else
  {
    lc.setLed(0,x_translate,y_translate,false); 
  }
   
  delay(150);
}
