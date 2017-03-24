#include "MoveBackwardWithEncoders.h"

MoveBackwardWithEncoders::MoveBackwardWithEncoders(float autondistance,float autonbasespeed)
{
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void MoveBackwardWithEncoders::Initialize()
{
	SmartDashboard::PutBoolean("Initializing movebackwardswithencoders", true);
	CommandBase::driveBase->ResetEncoders();
	driveBase->SetTargetState(false); //we are now looking for a target.
}

// Called repeatedly when this Command is scheduled to run
void MoveBackwardWithEncoders::Execute(float autondistance,float autonbasespeed)
{

	CommandBase::driveBase->ResetEncoders();	//pb
	driveBase->SetTargetState(false); 	//pb
	SmartDashboard::PutBoolean("about to do the test before we move", driveBase->GetTargetState());
	if(driveBase->GetTargetState() == false)		//we are looking for a target
	{
		CommandBase::driveBase->DriveBackward(autondistance, autonbasespeed);
	}

		//drive backwards will set the target state to true and stop the motors when it reaches the target.
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBackwardWithEncoders::IsFinished()
{
	SmartDashboard::PutBoolean("testing to see if the command is finished", driveBase->GetTargetState());
	return driveBase->GetTargetState();
}

// Called once after isFinished returns true
void MoveBackwardWithEncoders::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBackwardWithEncoders::Interrupted() {

}
