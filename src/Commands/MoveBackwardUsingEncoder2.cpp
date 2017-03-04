#include "MoveBackwardUsingEncoder2.h"

MoveBackwardUsingEncoder2::MoveBackwardUsingEncoder2() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void MoveBackwardUsingEncoder2::Initialize() {
	CommandBase::driveBase->DriveBackward(KSlowSpeed, KDistance2);
}

// Called repeatedly when this Command is scheduled to run
void MoveBackwardUsingEncoder2::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveBackwardUsingEncoder2::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveBackwardUsingEncoder2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBackwardUsingEncoder2::Interrupted() {

}
