/* Ohmmeter displayed on an LCD */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int analogPin=0;
int x=0;
float Vout=0;
float R=10000;        // create variables
float resistor=0;
float buffer=0;

void setup()
{

lcd.begin(16,2);
lcd.setCursor(0,0);        // start and print on LCD
lcd.print("Resistance");

}
void loop()
{

x=analogRead(analogPin);
buffer=x*5;
Vout=(buffer)/1024.0;
buffer=(5/Vout)-1;       // conversion of analog read to ohms using a reference resistor
resistor=R*buffer;
lcd.setCursor(0,1);
lcd.print("R = ");
lcd.print(resistor);
lcd.print(" Ohm");
delay(3000);
}