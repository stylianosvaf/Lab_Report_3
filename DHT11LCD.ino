#include <dht.h>
#include <LiquidCrystal.h>  // include librarys for LCD and DHT

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // set pins for LCD

#define DHT11_PIN 7  // set pin for DHT!!

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);      // set position to first row and print temperature in celsius
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);        // set postion to second row and print humidity in %
  lcd.print("%");
  delay(1000);
}