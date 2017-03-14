#include <Commands/FlywheelIncreaseSpeed.h>
#include "SmartDashboard/SmartDashboard.h"

FlywheelIncreaseSpeed::FlywheelIncreaseSpeed() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void FlywheelIncreaseSpeed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelIncreaseSpeed::Execute() {
	SmartDashboard::PutBoolean("Increasing shooter speed", true);
	CommandBase::shooter->AdjustShooterSpeed(20);
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelIncreaseSpeed::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void FlywheelIncreaseSpeed::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelIncreaseSpeed::Interrupted() {

}
