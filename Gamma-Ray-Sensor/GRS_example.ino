/*
  GRS_example.ino
  This code demonstrates the use of the GRS class and transmits
  both the raw AD conversion result and a calculated voltage 
  over the serial at 9600 Baud.
  Author: Anna Zovaro
  Date: 13th of September, 2014
*/

#include <stdlib.h>
#include <stdio.h>

#include "GRS.h"
#include "Arduino.h"

#define PIN 3          // analog input pin

GRS gammaRaySensor(PIN); // GRS object
double val = 0;          // variable to store read value
int rawVal = 0;          // variable to store raw ADC result

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  // sending the data over serial
  rawVal = gammaRaySensor.getAnalogReadVal();
  val = gammaRaySensor.getVoltage();
  // printing the values over serial
  Serial.print("Voltage: "); Serial.println(val);  
  Serial.print("Raw value: "); Serial.println(rawVal);  
  delay(100);
}
