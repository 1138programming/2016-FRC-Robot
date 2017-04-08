#include "AutonomousCenterGear.h"
#include "Subsystems/DriveBase.h"

AutonomousCenterGear::AutonomousCenterGear() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void AutonomousCenterGear::Initialize() {
//	CommandBase::driveBase->ResetEncoders();
	driveBase->SetEncoderReference();		//adjust the starting encoder position
	driveBase->SetLeftEncoderReference();
	driveBase->SetTargetState(false); //we are now looking for a target.
}

// Called repeatedly when this Command is scheduled to run
void AutonomousCenterGear::Execute()
{
	if(driveBase->GetTargetState() == false)		//we are looking for a target
	{
		CommandBase::driveBase->DriveBackwardS(KRevsToBaseLine, KAutonStraightSpeed);
	}
	//drive backwards will set the target state to true and stop the motors when it reaches the target.
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCenterGear::IsFinished() {
//	SmartDashboard::PutBoolean("This should eventually go to true", driveBase->GetTargetState());
	return driveBase->GetTargetState();
//	return false;
}

// Called once after isFinished returns true
void AutonomousCenterGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCenterGear::Interrupted() {

}
