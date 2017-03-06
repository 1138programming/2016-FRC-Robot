#include "VisionTracking.h"

VisionTracking::VisionTracking() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void VisionTracking::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void VisionTracking::Execute()
{
	//CommandBase::driveBase->GetDistance();
	//CommandBase::driveBase->IsUltrasonicRangeValid();
		SmartDashboard::PutBoolean("Is Vision On?", true);
		gearcam->displaySerialData(gearcam->receiveVision(),
									gearcam->decoder(gearcam->pixyData[0],
									gearcam->pixyData[1],
									gearcam->pixyData[2]),
									gearcam->decoder(gearcam->pixyData[3],
									gearcam->pixyData[4],
									gearcam->pixyData[5]));
}

// Make this return true when this Command no longer needs to run execute()
bool VisionTracking::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void VisionTracking::End() {
	SmartDashboard::PutBoolean("Is Vision On?", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionTracking::Interrupted() {

}
