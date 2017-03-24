#include "TurnToFacePilotTower.h"

TurnToFacePilotTower::TurnToFacePilotTower(float autonturndegrees,float autonturnspeed, bool autonleftturn)
{
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void TurnToFacePilotTower::Initialize()
{
	driveBase->ResetGyro();
	driveBase->SetTargetState(false);	//looking for a target
}

// Called repeatedly when this Command is scheduled to run
void TurnToFacePilotTower::Execute(float autonturndegrees, float autonturnspeed, bool autonleftturn)
{
	if(driveBase->GetTargetState() == false)		//we are looking for a target
	{
		CommandBase::driveBase->TurnWithBase(autonturndegrees, autonturnspeed, autonleftturn);
	}
//turnwithbase will set the target state to true and stop the motors when it reaches the target.
}

// Make this return true when this Command no longer needs to run execute()
bool TurnToFacePilotTower::IsFinished()
{
	return driveBase->GetTargetState();
}

// Called once after isFinished returns true
void TurnToFacePilotTower::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToFacePilotTower::Interrupted() {

}
