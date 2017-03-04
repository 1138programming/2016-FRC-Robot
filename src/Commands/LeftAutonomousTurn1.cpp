#include "LeftAutonomousTurn1.h"
//This command turns right for the first left autonomous turn

LeftAutonomousTurn1::LeftAutonomousTurn1() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void LeftAutonomousTurn1::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LeftAutonomousTurn1::Execute() {
	CommandBase::driveBase->BaseTurnRight(KLeftTurn1);
}

// Make this return true when this Command no longer needs to run execute()
bool LeftAutonomousTurn1::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LeftAutonomousTurn1::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftAutonomousTurn1::Interrupted() {

}
