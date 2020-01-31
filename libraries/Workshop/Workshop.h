/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Workshop_h
#define Workshop_h

// include types & constants of Wiring core API
#include "Arduino.h"

// library interface description
class Ultrasonic
{
  // user-accessible "public" interface
public:
  long duration;
  int distance, trigPin, echoPin;
  Ultrasonic(int, int);
  void getData(void);
};

//MPU6050
class MPU6050
{
public:
  MPU6050(void);
  void getData(void);
  void setupMPU(void);
  void recordAccelRegisters(void);
  void processAccelData(void);
  void recordGyroRegisters(void);
  void processGyroData(void);

  long accelX, accelY, accelZ;
  float gForceX, gForceY, gForceZ;
  long gyroX, gyroY, gyroZ;
  float rotX, rotY, rotZ;
};

class Motor
{
public:
  Motor(int, int);
  int mpin1,mpin2;
  void left(void);
  void right(void);
  void stop(void);
};
#endif
