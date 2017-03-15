#include "DisengageShooter.h"

DisengageShooter::DisengageShooter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void DisengageShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DisengageShooter::Execute()
{
//	if(CommandBase::shooter->QueryShooterState() == true)//If the shooter is on...
//	{
		CommandBase::shooter->FiltersOFF();
//		CommandBase::shooter->StopCollector(); //...shut all the motors off
		CommandBase::shooter->FlywheelsOFF();

//		CommandBase::shooter->SetShooterState(false);
//	}

}

// Make this return true when this Command no longer needs to run execute()
bool DisengageShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DisengageShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DisengageShooter::Interrupted() {

}
