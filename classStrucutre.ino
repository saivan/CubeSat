

// The satellite class houses the other components
class Sattelite{

  private:
    ADCSUnit    attitudeUnit();
    COMSystem   communications();
    // other systems should be their own class
  public:
    // User accessable sattelite methods
}


// Declaring the ADCS system
class ADCSUnit{
  public:
    vector3D determineAttitude();
    vector3D determinePosition();
    void controlLoop();
  
  private:
    vector3D currentAttitude;
    vector3D currentPosition;
}


// Declaring the communication system
class COMSystem{
  public:
    void sendMessage( string str );
    void beakonSignal();
  private:
    

}

// Declare other systems below

