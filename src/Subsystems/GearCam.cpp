/*
 * GearCam.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: eeuser
 */

#include <Subsystems/GearCam.h>
#include "Commands/VisionTracking.h"

GearCam::GearCam() :
	Subsystem("GearCam")
{
	initVision();
}

void GearCam::InitDefaultCommand()
{

}

void GearCam::initVision()
{
	serialPort = new SerialPort(9600, SerialPort::kMXP);
}

int GearCam::receiveVision()
{
	int receivedBytes = 0 ;
	serialPort->Write("a",1) ;
	receivedBytes = serialPort->Read(pixyData,6) ;
	serialPort->Write(pixyData, 6) ;
	return receivedBytes ;
}

double GearCam::decoder(char hundreds, char tens, char singles)
{
	return (((double(hundreds) - 48.0) * 100.0) +
			((double(tens) - 48.0) * 10.0) +
			((double(singles) - 48.0) * 1.0)) ;
}

double GearCam::displaySerialData(int received, double x, double l)
{
	SmartDashboard::PutNumber("bytes", received) ;
	SmartDashboard::PutNumber("valueX", x) ;
	SmartDashboard::PutNumber("valueL", l) ;
	return (x);
}
