/*
 * Shooter.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf and Nighthawk
 *
 */

#include <Subsystems/Shooter.h>

Shooter::Shooter() :

Subsystem("ShooterSubsystem")
{
	// Initialize talons used by Shooter subsystem
	flywheelRightTalon = new Talon();
}

void Shooter::InitDefaultCommand() {

}
