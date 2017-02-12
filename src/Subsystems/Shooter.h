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

	// Flywheel Control
	void		FlywheelsOff();
	void		FlywheelsForward(float speed=1.0);
	void		FlywheelsBackward(float speed=1.0);

	//Quadrature Functions
	double		GetEncPos();
	void		ResetEncPos();

	// Filter Control
	void		FiltersOn(float speed=1.0);
	void		FiltersOff();

	void		DoPIDControl(double P,double I,double D);
};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
