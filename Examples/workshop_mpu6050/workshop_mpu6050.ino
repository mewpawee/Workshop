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
  Serial.print("ax=");
  Serial.println(mpu.accelX);
  Serial.print("gx=");
  Serial.println(mpu.gForceX);
  Serial.print("gyx=");
  Serial.println(mpu.gyroX);
  Serial.print("rx=");
  Serial.println(mpu.rotX);
  
}
