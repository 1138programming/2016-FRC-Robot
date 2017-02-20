/*
 * FlywheelsOff.cpp
 * By Wolf - 2/11/2017
 */

#include <Commands/FlywheelsOff.h>

FlywheelsOff::FlywheelsOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter.get());
}

// Called just before this Command runs the first time
void FlywheelsOff::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelsOff::Execute() {
	CommandBase::shooter.get()->FlywheelsOff();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelsOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlywheelsOff::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelsOff::Interrupted() {

}
