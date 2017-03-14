/*
 * FiltersOff.cpp
 * By Wolf - 2/11/2017
 */

#include <Commands/FiltersOff.h>

FiltersOff::FiltersOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void FiltersOff::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FiltersOff::Execute() {
	CommandBase::shooter->FiltersOFF();
}

// Make this return true when this Command no longer needs to run execute()
bool FiltersOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FiltersOff::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FiltersOff::Interrupted() {

}
