/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Tester_h
#define Tester_h

// include types & constants of Wiring core API
#include "Arduino.h"

// library interface description
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

#endif
