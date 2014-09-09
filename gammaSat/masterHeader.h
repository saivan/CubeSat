

#ifndef HEADER_FILE
#define HEADER_FILE

// This master header file contains all of our classes, they are defined exterenally in their respective ino files
typedef enum { X_COM, Y_COM, Z_COM } component;

 // We have mode codes to define the mode we are working with
typedef enum {                          
        NORMAL,  SAFE,  RECOVERY,  TECHNOLOGY_DEMO,  PAYLOAD,  DATA_TRANSMIT,  CHECKOUT
} satMode ;

// This defines the 3D vector class 
class vector3D{
  public:
    void setComponent( component inputComponent, double value );
    void setVector( double x, double y, double z );
    double getComponent ( component request );    
  private:
    double x;
    double y;
    double z;
};

// This defines the GPS class
class GPSUnit{
 
}; 


// This defines the 
class ADCSUnit{
  public:
    void determineAttitude();
    void determinePosition();
    void controlLoop();  
  private:
    vector3D *currentAttitude;
    vector3D *currentPosition;
};

// This defines the communication System
class COMSystem{
  public:
    void sendData( char *str );
    void beaconSignal();
    satMode getMode(); //Receive command from ground station about desired mode.
  private:

};

// We have the payload system here
class Payload{
  public: 
    int senseGamma();
  private:
  
};


// This is the defintion of our satellite class
class satellite{
  public:    
    satellite();                                                // The constructor for the satellite
    void setMode( satMode modeCode = NORMAL );                  // Returns true if the mode was successfully set (defaults to normal)
    bool sendBeacon();                                          // Sends out the beacon, called periodically
  private:
    satMode satelliteMode;
  protected:  
    GPSUnit *positioningSystem;                                 // We point to the gps class and call its methods by gpsSystem->method()
    ADCSUnit *attitudeSystem;                                // We also point to an ADCS
    COMSystem *communications;                              // And a communications system
    Payload *payload;                               
    
};

#endif


