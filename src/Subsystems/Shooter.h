/*
 * Shooter.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "Encoder.h"

class Shooter: public frc::Subsystem {
private:
	CANTalon* flywheelRightTalon;
	CANTalon* flywheelLeftTalon;

	CANTalon* filterLeftTalon;
	CANTalon* filterRightTalon;
public:
	Shooter();
	// To understand the override keyword in InitDefaultCommand(),
	// see http://stackoverflow.com/a/13880274
//	Return type	Command								Keywords
	void		InitDefaultCommand()				override;

	// Flywheel Control - Always send positive values; code will adjust as necessary
	void		FlywheelsOff();
	void		FlywheelsForward(float speed=0.0); // 0.0 uses default speed; else
	void		FlywheelsBackward(float speed=0.0); // it will use overrided speed

	// Default Flywheel Control Variables; Change as necessary, but keep POSITIVE
	float flywheelForwardSpeed = 1.0;
	float flywheelBackwardSpeed = 1.0;

	//Quadrature Functions
	double		GetEncPos();
	void		ResetEncPos();

	// Filter Control
	void		FiltersOn(float speed=1.0);
	void		FiltersOff();

	void		DoPIDControl(float target=1.0, double kP=0.0, double kI=0.0, double kD=0.0);

};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
