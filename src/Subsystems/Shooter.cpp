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
	flywheelLeft = new CANTalon(KFlywheelLeftTalon);
	flywheelRight = new CANTalon(KFlywheelRightTalon);

	// Make the left talon both inverted and enable control
	flywheelLeft->EnableControl();
	flywheelLeft->SetSafetyEnabled(false);
	flywheelLeft->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	flywheelRight->SetInverted(true);

	// Zero out quadrature encoder
	flywheelLeft->SetPosition(0);

	filterFrontMotor = new CANTalon(KFilterFrontTalon);
	filterRearMotor = new CANTalon(KFilterRearTalon);

	// Make the left filter inverted, and enable control
	filterFrontMotor->EnableControl();
	filterFrontMotor->SetSafetyEnabled(false);
	filterFrontMotor->SetInverted(true);

	// Make the rear talon a slave to the front one
	filterRearMotor->SetControlMode(CANTalon::kFollower);
	filterRearMotor->Set(KFilterFrontTalon);
}

void Shooter::InitDefaultCommand() {
}

/*
 * Flywheel Functions
 * 2/11/17 - Wolf
 */

void Shooter::FlywheelsOff() {
	flywheelLeft->Set(0);
}

void Shooter::FlywheelsForward(float speed /* = default speed */) {
	if (speed == 0.0) {
		flywheelLeft->Set(flywheelForwardSpeed);
	} else {
		flywheelLeft->Set(speed); // Fowards movement based on custom value
	}
}

void Shooter::FlywheelsBackward(float speed /* = default speed */) {
	if (speed == 0.0) {
		flywheelLeft->Set(-flywheelBackwardSpeed);
	} else{
		flywheelLeft->Set(-speed);
	}
}

/*
 * Quadrature Functions
 * 2/11/2017 - Wolf
 */
double Shooter::GetEncPos() {
	return flywheelLeft->GetPosition();
}

void Shooter::ResetEncPos() {
	flywheelLeft->SetPosition(0);
}

/*
 * Filter Bag Motors
 * 2/11/17 - Wolf
 */
void Shooter::FiltersOn(float speed /* = default */) {
	if (speed == 0.0) {
		filterFrontMotor->Set(filterSpeed);
	} else {
		filterFrontMotor->Set(speed);
	}
}

void Shooter::FiltersOff() {
	filterFrontMotor->Set(0);
}

/*
 * PID Control
 * 2/11/17 - Wolf and PID man
 */

void Shooter::DoPIDControl(float target /* = 1.0 */, double kP /* = 0.0 */,
						   double kI /* = 0.0 */, double kD /* = 0.0 */)
{
	flywheelLeft->Set(target);
	flywheelLeft->SetPID(kP,kI,kD);
}
