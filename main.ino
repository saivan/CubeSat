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

void main()
{
    gammaSatMode = TTC.getMode(); // the mode is changed by a command from the groundstation    
    if(!gammaSat.changeMode(gammaSatMode))
      gammaSat.changeMode(SAFE);  // going into safe mode if error has occurred
}

// changes the operational mode of the satellite
// returns 0 if change successful, -1 otherwise
// we will define this as a method of the Satellite class at some point
int changeMode(int mode)
{  switch(mode)
  {
    case NORMAL:
    {
      normal_mode();
      return 0;   
    }
    case RECOVERY:
    {
      recovery_mode();
      return 0;   
    }   
    case SAFE:
    {
      safe_mode();
      return 0;
    }
    case PAYLOAD:
    {
      science_mode();
      return 0;
    }
    case DATA_TRANSMIT:
    {
      transmission_mode();
      return 0;
    }
    case TECHNOLOGY_DEMO:
    {
      technology_mode();
      return 0;
    }
    default:
      return -1;  // error has occurred
    
  }
      /* REPLACE WITH SWITCH STATEMENT
    if (satellite_mode == NORMAL_MODE)
    {
  
    }
    else if (satellite_mode == SAFE_MODE)
    {
  
    }
    else if (satellite_mode == RECOVERY_MODE)
    {
  
    }
    else if (satellite_mode == TECHNOLOGY_DEMO_MODE)
    {
  
    }
    else if (satellite_mode == PAYLOAD_MODE)
    {
        DetermineAttitude();
        
    } 
    else if (satellite_mode == DATA_TRANSMIT_MODE)
    {
        transmit_data();
  
    }
    else if (satellite_mode == CHECKOUT_MODE)
    {
        
    } 
    */
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
