// This function is called once a minute over the course of the entire mission.
// Each time it is called, it returns a string of the required format which is to be stored in the whole orbit data packet.
// currentIndex is to be incremented by WOD_PACKET_SIZE after each call.
// A total of 37 WOD packet 'chunks' are to be fit into each WOD packet to be transmitted to the ground station.
char * WOD::getWOD(char * WODPacket, unsigned int currentIndex)	
{		
	char WODPacketChunk[WOD_PACKET_SIZE];	// WOD_PACLET_SIZE = 57
	// First bit of WOD packet: 1 if payload operational; 0 otherwise
	int satStatus;
	if (payload.isOperational())
		satStatus = 1;
	else
		satStatus = 0;
		
	// other data fields
	long unsigned int time = OBC.getTime(); // time since 01/01/2000 UTC in s (data is already implemented in little endian formatting on the Uno)
	short unsigned int batteryVoltage = EPS.getBatteryVoltage();
	String batteryVoltageString = String(batteryVoltage);
	short unsigned int batteryCurrent = EPS.getBatteryCurrent();
	String batteryCurrentString = String(batteryCurrent);
	short unsigned int _3V3BusCurrent = EPS.get3V3BusCurrent();
	String _3V3BusCurrentString = String(_3V3BusCurrent);
	short unsigned int _5VBusCurrent = EPS.get5VBusCurrent();
	String _5VBusCurrentString = String(_5VBusCurrent);
	short unsigned int tempCOMM = TTC.getTemp();
	String tempCOMM = String(tempCOMM);
	short unsigned int tempEPS = EPS.getTemp();
	String tempEPSString = String(tempEPS);
	short unsigned int tempBattery = EPS.getBatteryTemp();
	String tempBatteryString = String(tempBattery);
	// Then concatenate these values into a string of the correct formatting:
	WODPacketString = String(satStatus + batteryVoltageString + batteryCurrentString + _3V3BusCurrentString + _5VBusCurrentString + tempCOMM + tempEPSString + tempBatteryString);
	// converting to char array
	WODPacketString.toCharArray(WODPacketChunk, sizeof(WODPacket));	// converting to char array
	WODPacket[currentIndex] = WODPacketChunk;	// storing the the WOD packet string to be sent to the ground station once it is filled.
}
