/*
 * FlywheelsBackward.cpp
 * By Wolf - 2/11/2017
 */

#include <Commands/FlywheelsBackward.h>

FlywheelsBackward::FlywheelsBackward() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter.get());
}

// Called just before this Command runs the first time
void FlywheelsBackward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelsBackward::Execute() {
	CommandBase::shooter.get()->FlywheelsBackward();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelsBackward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FlywheelsBackward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelsBackward::Interrupted() {

}
