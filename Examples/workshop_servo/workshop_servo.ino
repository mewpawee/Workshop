#include <Servo.h>
Servo myservo; //declare the variable
void setup()
{
myservo.attach(9); //attach to pin no.9
}
void loop()
{
myservo.write(-90); //rotate to -90 degree
delay(1000); // delay for 1000ms
myservo.write(90); //rotate to 90 degree
delay(1000); // delay for 1000ms
myservo.write(180); //rotate to 180 degree
delay(1000); // delay for 1000ms
}
