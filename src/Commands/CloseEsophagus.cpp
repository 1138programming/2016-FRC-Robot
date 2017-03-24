#include "CloseEsophagus.h"

CloseEsophagus::CloseEsophagus() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(esophagus);
}

// Called just before this Command runs the first time
void CloseEsophagus::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CloseEsophagus::Execute()
{
	CommandBase::esophagus->closeEsophagus();
}

// Make this return true when this Command no longer needs to run execute()
bool CloseEsophagus::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CloseEsophagus::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseEsophagus::Interrupted() {

}
