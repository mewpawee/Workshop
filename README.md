# CIE Workshop Documentation

### Motor

##### Library

###### Workshop.h



##### Class

###### Motor(first_pin, second_pin)

   Class name Motor with set up the first and the second pin connected via wire.



##### Functions

###### counter_clockwise(void)

   Make a motor rotate counter clockwise.

###### clockwise(void)

   Make a motor rotate clockwise.



##### Example

```
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
```



------

### Servo

##### Library

###### Servo.h



##### Class

###### Servo(void)

   Class name servo.



##### Functions

###### attach(pin)

   Declare with data pin attached to.   

###### write(degree)

   Make a servo rotate to that particular degree.



##### Example

```
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
```



------

### DHT

##### Library

###### Workshop.h



##### Class

###### DHT(data_pin)

   Class name DHT with the initialize on data pin.



##### Functions

###### getData(void)

   Get the data from sensor and store data on temp and humid variables.



##### Variables

###### temp

   Variable stores the temp data(Celsius).

###### humid

   Variable stores the humidity(Percent).



##### Example

```
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
```



------

### Display

##### Library

###### Adafruit_SSD1306.h



##### Class

###### Adafruit_SSD1306(int reset)

   Class name with the OLED_RESET declaration.



##### Functions

###### begin(void)

​    Initialize the screen

###### clearDisplay(void)

   Reset the screen.

###### println(text)

   Print a text as a line.

###### print(text)

   Print a text.

###### display(void)

   Display what you print on the screen.



##### Example

```
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(1);
void setup() {
display.begin(); 
display.clearDisplay(); 

display.setCursor(0,0);
display.println("Hi All to");
display.println("heyAll");
display.println("www.ArduinoAll.com");
display.display();
}

void loop() {
  for(int i =0;i < 20;i++){
  display.setCursor(0,50);
  display.print(i);
  display.display();
  }
  display.clearDisplay();
}
```



------

##### MPU6050

##### Library

###### Workshop.h



##### Class 

###### MPU6050(void)

   Class name MPU6050



##### Functions

###### setupMPU(void)

   Initialize the MPU

###### getData(void)

   Get the data from the sensor and store to the variables.



##### Variables

###### gForceX,gForceY,gForceZ

   Acceleration on X, Y, Z axes.

###### rotX, rotY, rotZ

   Gyro on X,Y,Z axes.



##### Example

```
#include <Workshop.h>
MPU6050 mpu;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mpu.setupMPU();
}

void loop() {
  delay(1000);
  mpu.getData();
  Serial.print("gx=");
  Serial.println(mpu.gForceX);
  Serial.print("rx=");
  Serial.println(mpu.rotX);
  
}
```



------

### Ultrasonic

##### Library

###### Workshop.h



##### Class

###### Ultrasonic(triger_pin, echo_pin)

   Class name Ultrasonic with the declaration on triger pin and echo pin.



##### Functions

###### getData(void)

   Get data from the  sensor and store to the variables.



##### Variables

###### distance

   Variables stored the distance.



##### Example

```
#include <Workshop.h>
Ultrasonic ultra_sonic(9,10); //trig,echo
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  ultra_sonic.getData();
  Serial.println(ultra_sonic.distance);
}
```





