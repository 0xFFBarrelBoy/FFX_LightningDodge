
#include <Servo.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 50;
const int colorG = 50;
const int colorB = 50;

const int pinLight = A0;
Servo Servo1;
int dodgecount = 0; 

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("Dodge Count:");
    Servo1.attach(2);
    Servo1.write(100);
}

void loop() 
{
  int lightvalue = analogRead(pinLight);
    // reads from light sensor
    lcd.setCursor(3, 1);
    lcd.print(dodgecount);
    // prints number of successful dodges to LCD 
    if(lightvalue>570){
      Servo1.write(85);
      delay(500);
      Servo1.write(100);
      dodgecount++;
      // If the light sensor is triggered, rotates the servo, holds position and returns back to original position.
    }

    delay(100);
}
