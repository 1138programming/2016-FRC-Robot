/*
 * FlywheelsForward.cpp
 * By Wolf - 2/11/2017
 */

#include <Commands/FlywheelsForward.h>

FlywheelsForward::FlywheelsForward() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter.get());
}

// Called just before this Command runs the first time
void FlywheelsForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelsForward::Execute() {
	CommandBase::shooter.get()->FlywheelsForward();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelsForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlywheelsForward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelsForward::Interrupted() {

}
