/* Voltmeter displayed on an LCD */


#include "LiquidCrystal.h"  // LCD library for commands

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // set pins 

float input_voltage = 0.0;  // setting up datatype for decimal values
float temp=0.0;


void setup()
{
   Serial.begin(9600);  // set the speed for the serial monitor
   lcd.begin(16, 2);  // set LCD rows and columns 
   lcd.print("DIGITAL VOLTMETER");  // print text on LCD
}
void loop()
{
   int analog_value = analogRead(A0);  // make analog value an integer that reads pin A0
   input_voltage = (analog_value * 5.0) / 1024.0;  // convert analog value into voltage 

   
   if (input_voltage < 0.1)  // if the voltage is less than 0.1, consider it 0 volts
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);  // print text on a different line
    lcd.setCursor(0, 1);  // sets place on LCD
    lcd.print("Voltage= ");
    lcd.print(input_voltage);
    delay(300);
}
