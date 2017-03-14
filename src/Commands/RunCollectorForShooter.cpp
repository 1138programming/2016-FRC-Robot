#include "RunCollectorForShooter.h"

RunCollectorForShooter::RunCollectorForShooter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(collector);
}

// Called just before this Command runs the first time
void RunCollectorForShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunCollectorForShooter::Execute()
{
	CommandBase::collector->RunCollector(collector->KCollectorSlowSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunCollectorForShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunCollectorForShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunCollectorForShooter::Interrupted() {

}
