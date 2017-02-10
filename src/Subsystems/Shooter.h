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
public:
	Shooter();
	// Initialization
	void InitDefaultCommand() override;

	// Flywheel Control
	void FlywheelsOff();
	void FlywheelsForward(float speed=1.0);
	void FlywheelsBackward(float speed=1.0);
};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
