/*
 * Shooter.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf and Nighthawk
 *
 */

#include <Subsystems/Shooter.h>
#include "CANTalon.h"
/*
 * List of motors and talons for Shooter
 *
 * Quad encoder - standard vex SRX mag encoder
 * 4 Motors in Total
 * 		2 on shooters - cims
 * 		2 bag motors on belt
 * 		1 cim reversed on both the belt and shooter (Unknown which)
 *
 * Talons:
 * Flywheel right: 5
 * Flywheel left: 6
 *
 */

Shooter::Shooter() :

frc::Subsystem("ShooterSubsystem")
{
	// Initialize talons used by Shooter subsystem
	flywheelRightTalon = new CANTalon(5);
	flywheelLeftTalon = new CANTalon(6);
}

void Shooter::InitDefaultCommand() {

}
