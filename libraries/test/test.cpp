/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "test.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"
#include "Wire.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

GY512::GY512(void)
{
  Wire.begin();
}

// Public Methods //
void GY512::test(void)
{
  GY512::testvar = 100;
}
