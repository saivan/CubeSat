/*
  GPS.h - a library for parsing NMEA data from a U-blox NEO-6M GPS module
  (specifically the GY-GPS6MV2).
  Created by Anna Zovaro, September 7, 2014.
*/
#ifndef GPS_h
#define GPS_h

#include "Arduino.h"
#include <SoftwareSerial.h>
#include <stdlib.h>

#define  DEBUG 1
#undef    DEBUG
#define  BUFF_LEN 230
#define  NELMS 4      // number of output GPS data elements
#define  GPS_TX  13   // Arduino receives on this pin
#define  GPS_RX  11   // Arduino transmits on this pin

class GPS
{
  public: 
    String * getGPSData(char * buffer, SoftwareSerial &gpsSerial);  // gets time, date, latitude and longitude and stores them in an array of strings
    void setupGPS(SoftwareSerial &gpsSerial);
        
  private:  
    enum RecommendedMinimumParam {
    TIME,
    VALIDITY,
    LATITUDE,
    LAT_NORTH_SOUTH,
    LONGITUDE,
    LON_EAST_WEST,
    SPEED,
    TRUE_COURSE,
    DATE,
    VARIATION,
    VAR_EAST_WEST,
    CHECKSUM
    };  // RMC data fields    
    enum SatellitesInView {
    TOTAL_MSG_COUNT,
    MSG_NUM,
    TOTAL_SATS_IN_VIEW,
    SV_PRN,
    ELEVATION,  // DEG (0-90)
    AZIMUTH,  // DEG (0-359)
    SNR  // DB (0-99)
    };  // GSV data fields
    
    char buffer[BUFF_LEN];  // buffer to hold raw GPS data
    String buffStr;      // String to hold converted GPS data
    String dataStr[NELMS];
 
    // private functions
    String fillDataBuffer(char * buffer, SoftwareSerial &gpsSerial, int bufferLength);
    String getDataString(String buffString, String DataName);
    String parseData(String data, int ctr);    
    String getTime(String RMCData);
    String getDate(String RMCData);
    String getLatitude(String RMCData);
    String getLongitude(String RMCData);  // concatenate the degrees and the direction into one string

};

#endif
