#include "LeftAutonomousTurn2.h"

LeftAutonomousTurn2::LeftAutonomousTurn2() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void LeftAutonomousTurn2::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LeftAutonomousTurn2::Execute() {
	CommandBase::driveBase->BaseTurnRight(KLeftTurn2);
}

// Make this return true when this Command no longer needs to run execute()
bool LeftAutonomousTurn2::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LeftAutonomousTurn2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftAutonomousTurn2::Interrupted() {

}
