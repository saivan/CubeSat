//Declare essential fns (On at all times, regardless of the mode)
int gammaSat::essentialFunctions()
{
  satAttitude = ADCS.determineAttitude();
  satPosition = ADCS.determinePosition();
  COMsystem.controlLoop();
  COMsystem.beaconSignal();
}


//This will define each mode of operation
//These functions should return 0 to indicate no error, otherwise it will return -1 to indicate that
//there has been an error, in which case the gammaSat system will return to Safe mode

//Normal Mode
//All subsystems operational except for payload
//Activated after the inital recovery and detumble phases
int gammaSat::normalMode()
{
  essentialFunctions();
  
  
}

//Recovery Mode
//Beacon transmit, receive commands, GPS and attitude control
//Comunication with ground station initialised
int gammaSat::recoveryMode()
{
    essentialFunctions();

}

//Safe Mode
//Beacon transmit, receive commmands, GPS and attitude control
int gammaSat::safeMode()
{
    essentialFunctions();

}

//Science Mode
//Beacon transmit, receive commmands, GPS and attitude control
//Science payload ON
int gammaSat::scienceMode()
{
    essentialFunctions();

}

//Transmit Mode
//Beacon transmit, receive commmands, GPS and attitude control
//Transmit all data to ground station, when gammaSat is in view of the ground station
int gammaSat::transmissionMode()
{
    essentialFunctions();

}

//Technology Mode
//Beacon transmit, receive commmands, GPS and attitude control
//Technology payload ON
int gammaSat::technologyMode()
{
    essentialFunctions();

}

//Checkout Mode
//Beacon transmit, receive commmands, GPS and attitude control
//Diagnostic of all satellite components
int gammaSat::technologyMode()
{
    essentialFunctions();

}
