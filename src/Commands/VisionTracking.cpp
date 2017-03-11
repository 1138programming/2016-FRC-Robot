#include "VisionTracking.h"

VisionTracking::VisionTracking() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
	Requires(CommandBase::gearcam);
}

// Called just before this Command runs the first time
void VisionTracking::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void VisionTracking::Execute()
{
	SmartDashboard::PutBoolean("Is Vision On?", true);
	gearcam->displaySerialData(gearcam->receiveVision(),
										gearcam->decoder(gearcam->pixyData[0],
										gearcam->pixyData[1],
										gearcam->pixyData[2]),
										gearcam->decoder(gearcam->pixyData[3],
										gearcam->pixyData[4],
										gearcam->pixyData[5]));
	int average = (gearcam->decoder(gearcam->pixyData[0],gearcam->pixyData[1],gearcam->pixyData[2]));
	if(average < (340 + 40) && average > (340 - 40)){
		SmartDashboard::PutBoolean("Is Centered", true);
		SmartDashboard::PutString("Where is the object?", "Center");
				//Do centered driving actions
	}
	else if(average >= (340 + 40)){
		SmartDashboard::PutBoolean("Is Centered", false);
		SmartDashboard::PutString("Where is the object?", "Right");
			//object is in the right hand side view range

	}
	else if(average <= (340 - 40)){
		SmartDashboard::PutBoolean("Is Centered", false);
		SmartDashboard::PutString("Where is the object?", "Left");
				//object is in the left hand side view range
	}
}

// Make this return true when this Command no longer needs to run execute()
bool VisionTracking::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionTracking::End() {
	SmartDashboard::PutBoolean("Is Vision On?", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionTracking::Interrupted() {

}
