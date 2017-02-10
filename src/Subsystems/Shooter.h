/*
 * Shooter.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf and Nighthawk
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "CANTalon.h"

class Shooter: public frc::Subsystem {
private:
	CANTalon* flywheelRightTalon;
	CANTalon* flywheelLeftTalon;
public:
	Shooter();
	void InitDefaultCommand() override;
};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
