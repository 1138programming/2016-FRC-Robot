#include "DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize()
{
//	driveBase->LowShiftBase();
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute()
{
//	if (driveBase->QueryLiftState() == DoubleSolenoid::kForward)
//	{
//		CommandBase::driveBase->TankDrive(oi->getRightController(), oi->getRightController());
//	}
//	else
//	{
		CommandBase::driveBase->TankDrive(oi->getLeftController(), oi->getRightController());
//	}
}

// Make this return true when this Command no longer needs to run execute()

bool DriveWithJoysticks::IsFinished()
{
	return false;
}

// Called once after isFinished returns true

void DriveWithJoysticks::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {

}
