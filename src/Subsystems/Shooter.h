/*
 * Shooter.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf and Nighthawk
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"

class Shooter {
private:
	Talon flywheelRightTalon;
	Talon flywheelLeftTalon;
public:
	Shooter();
	void InitDefaultCommand();
};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
