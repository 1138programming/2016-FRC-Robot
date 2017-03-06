#include "ToggleLift.h"

ToggleLift::ToggleLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void ToggleLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleLift::Execute() {
	driveBase->EngageLift();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLift::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLift::Interrupted() {

}
