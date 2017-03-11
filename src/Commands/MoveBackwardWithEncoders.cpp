#include "MoveBackwardWithEncoders.h"

MoveBackwardWithEncoders::MoveBackwardWithEncoders(float autondistance,
												   float autonbasespeed) {
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void MoveBackwardWithEncoders::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveBackwardWithEncoders::Execute(float autondistance,
									   float autonbasespeed) {
	CommandBase::driveBase->DriveBackward(autondistance, autonbasespeed);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBackwardWithEncoders::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void MoveBackwardWithEncoders::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBackwardWithEncoders::Interrupted() {

}
