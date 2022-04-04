
#include <dht.h>
#define DHT11_PIN 9
dht DHT;



#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int PushB = 8;

float C = DHT.temperature;


void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
pinMode(PushB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(PushB) == false) {

  lcd.setCursor(0,0);
  lcd.print("Temperature in C: ");
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  lcd.print("C");

  }

  else if (digitalRead(PushB) == true){

    float F = (C*1.8)+32;
  lcd.setCursor(0,0);
  lcd.print("Temperature in F: ");
  lcd.setCursor(0,1);
  lcd.print(F);
  lcd.print("F");
    
    
    
    
    
    }



}
