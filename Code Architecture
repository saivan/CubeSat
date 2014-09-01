//Code Architecture - will contain modes of operation, main functions and the pin I/O setup routine

//Setup pin I/O for Due

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
  
    } 
    else if (satellite_mode == DATA_TRANSMIT_MODE)
    {
        transmit_data()
  
    }
    else if (satellite_mode == CHECKOUT_MODE)
    {
        
    } 
}


//FUNCTION DESCRIPTION
//ADCS
//Sensors - IMU, Sun sensors (compl. filter)
//Acquire data from sensors and fuse using complementary filter. Return data into Roll, Pitch and Yaw  variables.
DetermineAttitude()
//GPS
DeterminePosition()
//Magnetorquers
ApplyControl()

//Payload - Interrupts triggered when lightning detected. Can trigger interrupt if pin receives a pulse (ie goes from low to high).
attachInterrupt(pin, ISR, mode)
//start counting gamma rays when the lightning is detected.
GeigerCount()

//Communications
transmit_30s_ping() //Create timer interrupt every 30s??
transmit_data()
receive()
