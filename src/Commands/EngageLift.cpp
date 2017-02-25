#include "EngageLift.h"

EngageLift::EngageLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void EngageLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void EngageLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool EngageLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void EngageLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageLift::Interrupted() {

}
