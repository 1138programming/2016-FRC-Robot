/*
 * FiltersOn.cpp
 * By Wolf - 2/11/2017
 */

#include <Commands/FiltersOn.h>

FiltersOn::FiltersOn() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void FiltersOn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FiltersOn::Execute() {
	CommandBase::shooter->FlitersON();
}

// Make this return true when this Command no longer needs to run execute()
bool FiltersOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FiltersOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FiltersOn::Interrupted() {

}
