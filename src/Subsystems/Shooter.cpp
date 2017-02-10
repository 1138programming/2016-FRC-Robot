/*
 * Shooter.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf
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
	/*
	 *  Initialize talons used by Shooter subsystem
	 *  By Wolf 2/9/2017
	 *
	 *  Copied from Legends 2015-2016 code; modifications made to work
	 *  with Momentum talons
	 */
	flywheelLeftTalon = new CANTalon(6);
	flywheelRightTalon = new CANTalon(5);

	// Make the left talon both inverted and enable control
	flywheelLeftTalon->EnableControl();
	flywheelLeftTalon->SetSafetyEnabled(false);
	flywheelLeftTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
	flywheelLeftTalon->SetInverted(true);

	// Make the right talon a slave to the left one
	flywheelRightTalon->SetControlMode(CANTalon::kFollower);
	flywheelRightTalon->Set(6);
}

void Shooter::InitDefaultCommand() {
}

void Shooter::FlywheelsOff() {
	flywheelLeftTalon->Set(0);
}

void Shooter::FlywheelsForward(float speed /* = 1.0 */) {
	flywheelLeftTalon->Set(speed); // Fowards movement
}

void Shooter::FlywheelsBackward(float speed /* = 1.0 */) {
	flywheelLeftTalon->Set(-speed); // Backward movement; negate speed
}
