#include "DHT.h"

DHT dht(9);

void setup()
{
Serial.begin(9600);
}

void loop()
{
delay(2000);
dht.getData();
Serial.print("Humid ");
Serial.println(dht.humid);
Serial.print("Temp ");
Serial.println(dht.temp);
}
