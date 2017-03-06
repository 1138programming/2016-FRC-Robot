/*
 * GearCam.h
 *
 *  Created on: Feb 2, 2017
 *      Author: eeuser
 */

#ifndef SRC_SUBSYSTEMS_GEARCAM_H_
#define SRC_SUBSYSTEMS_GEARCAM_H_
#include "WPILib.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Subsystem.h"

class GearCam: public Subsystem
{
private:
	SerialPort *serialPort ;


public:
	GearCam();
	char pixyData[6]  = {0} ;
	void InitDefaultCommand() ;
	void displaySerialData(int received, double x, double l) ;
	double decoder(char hundreds, char tens, char singles) ;
	void initVision() ;
	int receiveVision() ;


};

#endif /* SRC_SUBSYSTEMS_GEARCAM_H_ */
