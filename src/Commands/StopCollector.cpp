#include "StopCollector.h"

StopCollector::StopCollector() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::collector);
}

// Called just before this Command runs the first time
void StopCollector::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void StopCollector::Execute() {
	CommandBase::collector->StopCollector();
}

// Make this return true when this Command no longer needs to run execute()
bool StopCollector::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopCollector::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCollector::Interrupted() {

}
