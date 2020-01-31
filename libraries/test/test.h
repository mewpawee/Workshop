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
class GY512
{
public:
  GY512(void);
  int testvar;
  void test();
};

#endif
