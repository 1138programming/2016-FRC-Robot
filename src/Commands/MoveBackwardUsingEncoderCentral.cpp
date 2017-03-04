#include "MoveBackwardUsingEncoderCentral.h"

MoveBackwardUsingEncoderCentral::MoveBackwardUsingEncoderCentral() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void MoveBackwardUsingEncoderCentral::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveBackwardUsingEncoderCentral::Execute() {
	CommandBase::driveBase->DriveBackward(KSlowSpeed, KDistanceCentral);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBackwardUsingEncoderCentral::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveBackwardUsingEncoderCentral::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBackwardUsingEncoderCentral::Interrupted() {

}
