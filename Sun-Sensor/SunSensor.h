/*
  SunSensor - a library for reading raw analog inputs from sun sensors through a 4-bit analog multiplexer
  Author: Anna Zovaro
  Date: 14th September 2014
*/

#ifndef SunSensor_c
#define SunSensor_c

#include "Arduino.h"

void setupSS(int * pinout);
void getSSData(int * pinout, int nSensors, int * data);
int * muxSelect(int num);

#endif
