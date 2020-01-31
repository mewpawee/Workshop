#include <Workshop.h>
Ultrasonic ultra_sonic(9,10); //trig,echo
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  ultra_sonic.getData();
  Serial.println(ultra_sonic.distance);
}
