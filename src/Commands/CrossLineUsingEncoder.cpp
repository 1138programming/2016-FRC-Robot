#include "CrossLineUsingEncoder.h"

CrossLineUsingEncoder::CrossLineUsingEncoder() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void CrossLineUsingEncoder::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CrossLineUsingEncoder::Execute() {
	CommandBase::driveBase->DriveBackward(KSlowSpeed, KCrossingDistance);
}

// Make this return true when this Command no longer needs to run execute()
bool CrossLineUsingEncoder::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CrossLineUsingEncoder::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrossLineUsingEncoder::Interrupted() {

}
