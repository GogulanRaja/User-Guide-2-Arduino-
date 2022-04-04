


#include <SPI.h>
#include <SD.h>

#include <DHT.h>

int CSpin = 4;
File myDHT11Data;

#define DHTPIN 7
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

float Tempvalue = 0;
float Humvalue = 0;

void setup() {
  // put your setup code here, to run once:
SD.begin(CSpin);
dht.begin();
}

void loop() {
// put your main code here, to run repeatedly:
Tempvalue = dht. readTemperature();
Humvalue = dht. readHumidity();

myDHT11Data = SD.open("Gogu_SD.txt", FILE_WRITE);

myDHT11Data.print(Tempvalue);
myDHT11Data.print(",");
myDHT11Data.print(Humvalue);
myDHT11Data.println();
delay(500);
myDHT11Data.close();

}
