#include "MoveBackwardUsingEncoder1.h"

MoveBackwardUsingEncoder1::MoveBackwardUsingEncoder1() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void MoveBackwardUsingEncoder1::Initialize() {
	CommandBase::driveBase->DriveBackward(KSlowSpeed, KDistance1);
}

// Called repeatedly when this Command is scheduled to run
void MoveBackwardUsingEncoder1::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveBackwardUsingEncoder1::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveBackwardUsingEncoder1::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBackwardUsingEncoder1::Interrupted() {

}
