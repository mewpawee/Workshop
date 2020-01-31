#include <Workshop.h>
Motor motor(6,7); //(firstPin,secondPin)
void setup() {
  Serial.begin(9600);
}

void loop() {

  motor.clockwise();
  Serial.println("Motor clocwise");
  delay(2000);
  motor.stop();
  Serial.println("Motor STOP");
  delay(2000);
  motor.counter_clockwise();
  Serial.println("Motor conter_clockwise");
  delay(2000);


}
