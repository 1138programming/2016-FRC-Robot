#include "RightAutonomousTurn2.h"

RightAutonomousTurn2::RightAutonomousTurn2() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void RightAutonomousTurn2::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RightAutonomousTurn2::Execute() {
	CommandBase::driveBase->BaseTurnRight(KRightTurn2);
}

// Make this return true when this Command no longer needs to run execute()
bool RightAutonomousTurn2::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RightAutonomousTurn2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightAutonomousTurn2::Interrupted() {

}
