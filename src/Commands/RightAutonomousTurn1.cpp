#include "RightAutonomousTurn1.h"

RightAutonomousTurn1::RightAutonomousTurn1() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void RightAutonomousTurn1::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RightAutonomousTurn1::Execute() {
	CommandBase::driveBase->BaseTurnRight(KRightTurn1);
}

// Make this return true when this Command no longer needs to run execute()
bool RightAutonomousTurn1::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RightAutonomousTurn1::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightAutonomousTurn1::Interrupted() {

}
