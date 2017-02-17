/*
 * FlywheelsOn.cpp
 * By Wolf - 2/11/2017
 */

#include "FlywheelsOn.h"

FlywheelsOn::FlywheelsOn() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void FlywheelsOn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelsOn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelsOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlywheelsOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelsOn::Interrupted() {

}
