//Code Architecture - will contain modes of operation, main functions and the pin I/O setup routine

//Setup pin I/O for Due
void setup() {
  // put your setup code here, to run once:

}

//Modes of operation 
#define NORMAL_MODE 0
#define SAFE_MODE 1
#define RECOVERY_MODE 2
#define TECHNOLOGY_DEMO_MODE  3
#define PAYLOAD_MODE  4
#define DATA_TRANSMIT_MODE  5
#define CHECKOUT_MODE 6

int satellite_mode;

void main()
{
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
