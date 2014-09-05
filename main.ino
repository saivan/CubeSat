//Code Architecture - will contain modes of operation, main functions and the pin I/O setup routine


//Modes of operation 
enum Modes {
  NORMAL,
  SAFE,
  RECOVERY,
  PAYLOAD,
  DATA_TRANSMIT,
  TECHNOLOGY_DEMO,
  CHECKOUT
};
int gammaSatMode;

//Setup pin I/O for Due
void setup() {
  // put your setup code here, to run once:
  gammaSat.changeMode(RECOVERY);      // recovery mode - sets up all critical subsystems
  gammaSat.changeMode(CHECKOUT);      // checkout mode - diagnostic check of all subsystems; setup of all remaining subsystems
} 


void loop(){
    gammaSatMode = TTC.getMode(); // the mode is changed by a command from the groundstation    
    if(!gammaSat.changeMode(gammaSatMode))
      gammaSat.changeMode(SAFE);  // going into safe mode if error has occurred
}

// changes the operational mode of the satellite
// returns 0 if change successful, -1 otherwise
// we will define this as a method of the Satellite class at some point

// Once the mode has been changed, it will immediately begin to run in a loop
// Calling itself upon exiting.
int changeMode(int mode){  
  switch(mode){
    case NORMAL:
      gammaSat.normalMode();
      return 0;   
    case RECOVERY:
      gammaSat.recoveryMode();
      return 0;   
    case SAFE:
      gammaSat.safeMode();
      return 0;
    case PAYLOAD:
      gammaSat.scienceMode();
      return 0;
    case DATA_TRANSMIT:
      gammaSat.transmissionMode();
      return 0;
    case TECHNOLOGY_DEMO:
      gammaSat.technologyMode();
      return 0;
    default:
      return -1;  // error has occurred
  }
}

//FUNCTION DESCRIPTIONS
//ADCS
//Sensors - IMU, Sun sensors (compl. filter)
//Acquire data from sensors and fuse using complementary filter. Return data into Roll, Pitch and Yaw  variables.
void DetermineAttitude(){}
//GPS
void DeterminePosition(){}
//Magnetorquers
void ApplyControl(){}

//Other Sensors (temp, current, voltage, power consumption etc)
void ReadSensors(){}

//Payload - Interrupts triggered when lightning detected. Can trigger interrupt if pin receives a pulse (ie goes from low to high).
// Use fn below to generate interrupt on arduino
//attachInterrupt(pin, ISR, mode)

//start counting gamma rays when the lightning is detected.
void GeigerCount(){}

//Communications
//send ping with time, position and radio call sign every 30s
void transmit_30s_ping()
{
    DeterminePosition();
} //Create timer interrupt every 30s??

void transmit_data(){
    DetermineAttitude()
    
}
void receive(){}
