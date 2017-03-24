#include "OpenEsophagus.h"

OpenEsophagus::OpenEsophagus() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(esophagus);
}

// Called just before this Command runs the first time
void OpenEsophagus::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OpenEsophagus::Execute()
{
	CommandBase::esophagus->OpenEsophagus();
}

// Make this return true when this Command no longer needs to run execute()
bool OpenEsophagus::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void OpenEsophagus::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenEsophagus::Interrupted() {

}
