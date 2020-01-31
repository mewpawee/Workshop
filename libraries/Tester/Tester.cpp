/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "Tester.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"
#include "Wire.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

MPU6050::MPU6050(void)
{
  Wire.begin();
}

// Public Methods //
void MPU6050::getData(void)
{
  MPU6050::recordAccelRegisters();
  MPU6050::recordGyroRegisters();
}

void MPU6050::setupMPU()
{
  Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(0x6B);                  //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000);            //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1B);                  //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4)
  Wire.write(0x00000000);            //Setting the gyro to full scale +/- 250deg./s
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1C);                  //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5)
  Wire.write(0b00000000);            //Setting the accel to +/- 2g
  Wire.endTransmission();
}

void MPU6050::recordAccelRegisters()
{
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x3B);                  //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6); //Request Accel Registers (3B - 40)
  if (Wire.available() >= 6){
    accelX = Wire.read() << 8 | Wire.read(); //Store first two bytes into accelX
    accelY = Wire.read() << 8 | Wire.read(); //Store middle two bytes into accelY
    accelZ = Wire.read() << 8 | Wire.read(); //Store last two bytes into accelZ
  MPU6050::processAccelData();
  }
}

void MPU6050::processAccelData()
{
  gForceX = accelX * 9.81 / 16384.0;
  gForceY = accelY * 9.81 / 16384.0;
  gForceZ = accelZ * 9.81 / 16384.0;
}

void MPU6050::recordGyroRegisters()
{
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x43);                  //Starting register for Gyro Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6); //Request Gyro Registers (43 - 48)
  if (Wire.available() >= 6)
  {
    gyroX = Wire.read() << 8 | Wire.read(); //Store first two bytes into accelX
    gyroY = Wire.read() << 8 | Wire.read(); //Store middle two bytes into accelY
    gyroZ = Wire.read() << 8 | Wire.read(); //Store last two bytes into accelZ
    MPU6050::processGyroData();
  }
}

void MPU6050::processGyroData()
{
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0;
  rotZ = gyroZ / 131.0;
}
