#include "AutonomousLineDrive.h"
#include "RobotMap.h"
#include "Subsystems/DriveBase.h"

AutonomousLineDrive::AutonomousLineDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void AutonomousLineDrive::Initialize() {
	SmartDashboard::PutBoolean("Doing Line Drive Auton", true);
//	CommandBase::driveBase->ResetEncoders();
	driveBase->SetEncoderReference();		//adjust the starting encoder position
	driveBase->SetTargetState(false); //we are now looking for a target.
}

// Called repeatedly when this Command is scheduled to run
void AutonomousLineDrive::Execute()
{
	if(driveBase->GetTargetState() == false)		//we are looking for a target
	{
		CommandBase::driveBase->DriveBackward(KRevsToCrossTheLine, KAutonStraightSpeed);
	}
//		else
//		{
//			driveBase->SetTargetState(true);	//set that the target is reached.
//			driveBase->StopBase();		//target reached
//		}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousLineDrive::IsFinished()
{
	SmartDashboard::PutBoolean("This should eventually go to true", driveBase->GetTargetState());
//	return driveBase->GetTargetState();
	return false;
}

// Called once after isFinished returns true
void AutonomousLineDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousLineDrive::Interrupted() {

}
