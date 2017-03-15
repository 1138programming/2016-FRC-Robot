#include "TurnToFacePilotTower.h"

TurnToFacePilotTower::TurnToFacePilotTower(float autonturndegrees,
										   float autonturnspeed,
										   bool autonleftturn) {
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void TurnToFacePilotTower::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TurnToFacePilotTower::Execute(float autonturndegrees,
								   float autonturnspeed,
								   bool autonleftturn) {
	CommandBase::driveBase->TurnWithBase(autonturndegrees, autonturnspeed, autonleftturn);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnToFacePilotTower::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TurnToFacePilotTower::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToFacePilotTower::Interrupted() {

}
