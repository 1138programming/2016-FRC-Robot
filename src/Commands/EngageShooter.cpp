#include "EngageShooter.h"
#include "SmartDashboard/SmartDashboard.h"

EngageShooter::EngageShooter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void EngageShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void EngageShooter::Execute()
{
//	if(CommandBase::shooter->QueryShooterState() == false)//If the shooter is off...
//	{
//		SmartDashboard::PutBoolean("Shooter is about to be turned on", true);
//		CommandBase::shooter->SetShooterState(true);

		CommandBase::shooter->FlywheelsON(shooter->GetShooterTargetSpeed()); //...turn flywheels on

		if(CommandBase::shooter->GetShooterSpeed() >= shooter->GetShooterTargetSpeed())//If the shooter speed is greater
		{																//than or equal to ShootSpeed...
//			SmartDashboard::PutBoolean("Shooter is up to speed", true);
			CommandBase::shooter->FlitersON();
//			CommandBase::collector->RunCollector(collector->KCollectorSlowSpeed); //Turn collector and filter motors on
		}
		else	//Anything else...
		{
			CommandBase::shooter->FiltersOFF();
//			CommandBase::shooter->StopCollector();	//...turn them off
		}
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool EngageShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void EngageShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageShooter::Interrupted() {

}
