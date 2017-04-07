#include "VisionTracking.h"

VisionTracking::VisionTracking() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(CommandBase::driveBase);

}

// Called just before this Command runs the first time
void VisionTracking::Initialize()
{
	cam = CameraServer::GetInstance();

}

// Called repeatedly when this Command is scheduled to run
void VisionTracking::Execute()
{
	cam->StartAutomaticCapture(0);
	//CommandBase::driveBase->GetDistance();
	//CommandBase::driveBase->IsUltrasonicRangeValid();
//		SmartDashboard::PutBoolean("Is Vision On?", true);
//		gearCam->displaySerialData(gearCam->receiveVision(),
//									gearCam->decoder(gearCam->pixyData[0],
//									gearCam->pixyData[1],
//									gearCam->pixyData[2]),
//									gearCam->decoder(gearCam->pixyData[3],
//									gearCam->pixyData[4],
//									gearCam->pixyData[5]));
}

// Make this return true when this Command no longer needs to run execute()
bool VisionTracking::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionTracking::End() {
	//SmartDashboard::PutBoolean("Is Vision On?", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionTracking::Interrupted() {

}
