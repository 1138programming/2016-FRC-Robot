/*
 * Pneumatics.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: eeuser
 */

#include "Subsystems/Pneumatics.h"
#include "../RobotMap.h"


Pneumatics::Pneumatics() :
		frc::Subsystem("Pneumatics") {

		pCompressor = new Compressor(0);

		pressureSensor = new AnalogInput(0);
//	lw->AddSensor("Pneumatics", "pressureSensor", pneumaticspressureSensor);
}

void Pneumatics::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//default is closed loop control
	pCompressor->Start();
}
	// TODO Auto-generated constructor stub





