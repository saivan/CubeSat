
#include "masterHeader.h"

// This method initialises all of the satellites sub-parts
// This syntax is called an initialiser list, it runs SUPER fast
// compared to initialising in the members, the new keyword creates
// a new class and updates the pointer to point to them :) nifty!
satellite::satellite() :
    positioningSystem( new GPSUnit() ) ,
    attitudeSystem( new ADCSUnit() ),  
    communications( new COMSystem() ),
    payload( new Payload() )
{}


