#include "AutonomousRightSide.h"
//#define VISION

AutonomousRightSide::AutonomousRightSide() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
	Requires(CommandBase::gearCam);
}

// Called just before this Command runs the first time
void AutonomousRightSide::Initialize() {
//	SmartDashboard::PutBoolean("Initializing Autonomous Right Side", true);
//	CommandBase::driveBase->ResetEncoders();
	driveBase->SetEncoderReference();		//save the current encoder position
	driveBase->SetTargetState(false); //we are now looking for a target.
	driveBase->SetAutonStage(driveBase->KAutonFirstMove);	//lets start this.
}

// Called repeatedly when this Command is scheduled to run
void AutonomousRightSide::Execute() {
	if (driveBase->GetAutonStage() == driveBase->KAutonFirstMove)		//first stage
	{
//		SmartDashboard::PutBoolean("Auton Stage 1: Moving for the first time", true);
		driveBase->DriveBackward(KRevsToBaseLine, KAutonStraightSpeed);
		if(driveBase->GetTargetState() == true)
		{
			driveBase->SetTargetState(false); //we are now looking for the next target.
			driveBase->SetAutonStage(driveBase->KAutonTurn);	//move on to the second stage
			CommandBase::driveBase->ResetGyro();	//need to reset the gyro for second stage
//			SmartDashboard::PutNumber("Leaving Auton Stage 1", driveBase->GetAutonStage());
		}
	}
//	SmartDashboard::PutNumber("Trying to start stage 2",driveBase->GetAutonStage() );
//	SmartDashboard::PutBoolean("and the target state is ",driveBase->GetTargetState() );
	if (driveBase->GetAutonStage() == driveBase->KAutonTurn)		//second stage
	{
//		SmartDashboard::PutBoolean("Auton Stage 2: Turning", true);
		CommandBase::driveBase->TurnWithBase(KTurnToPilotTower, KAutonTurnSpeed, KRightTurn);
		if(driveBase->GetTargetState() == true)
		{
			driveBase->SetTargetState(false); //we are now looking for the next target.
			driveBase->SetAutonStage(driveBase->KAutonSecondMove);	//move on to the third stage
			SmartDashboard::PutNumber("This is the old relative encoder value", driveBase->GetEncoderReference());
			driveBase->SetEncoderReference();		//adjust the starting encoder position
//			SmartDashboard::PutNumber("This is the new relative encoder value", driveBase->GetEncoderReference());
	//		CommandBase::driveBase->ResetEncoders();	//need to reset the encoders for third stage.  This isn't working
		}
	}

	if (driveBase->GetAutonStage() == driveBase->KAutonSecondMove)		//third stage
	{
//		SmartDashboard::PutBoolean("Auton Stage 3: Moving towards the gear peg", false);
		driveBase->DriveBackward(KRevsToPilotTower, KAutonStraightSpeed);
#ifndef VISION
		if(driveBase->GetTargetState() == true)
		{
			driveBase->SetAutonStage(driveBase->KAutonFinished);	//move on to the third stage
		}
#endif
#ifdef VISION
		if(driveBase->GetTargetState() == true)
		{
			driveBase->SetTargetState(false); //we are now looking for the next target.
			driveBase->SetAutonStage(driveBase->KAutonVision1);	//move on to the fourth stage
			SmartDashboard::PutNumber("Leaving Auton Stage 3", driveBase->GetAutonStage());
		}
	}

	if (driveBase->GetAutonStage() == driveBase->KAutonVision1)		//fourth stage
	{
		SmartDashboard::PutBoolean("Auton Stage 4: Vision Tracking", true);
		gearCam->VisionForPeg();
		if(driveBase->GetTargetState() == true)
		{
			driveBase->SetTargetState(false); //we are now looking for the next target.
			driveBase->SetAutonStage(driveBase->KAutonVision2);	//move on to the third stage
			CommandBase::driveBase->ResetGyro();	//need to reset the gyro for fourth stage
			SmartDashboard::PutNumber("Leaving Auton Stage 4", driveBase->GetAutonStage());
		}
	}

	if (driveBase->GetAutonStage() == driveBase->KAutonVision2)		//fourth stage
		{
			SmartDashboard::PutBoolean("Auton Stage 5: Vision Tracking", true);
			//CommandBase::driveBase->TurnWithBase(KTurnToPegTip, KAutonTurnSpeed, KRightTurn); //TODO change values
			if(driveBase->GetTargetState() == true)
			{
				driveBase->SetTargetState(false); //we are now looking for the next target.
				driveBase->SetAutonStage(driveBase->KAutonVision3);	//move on to the third stage
				CommandBase::driveBase->SetEncoderReference();	//need to reset the gyro for fourth stage
				SmartDashboard::PutNumber("Leaving Auton Stage 5", driveBase->GetAutonStage());
			}
		}

	if (driveBase->GetAutonStage() == driveBase->KAutonVision3)		//fourth stage
			{
				SmartDashboard::PutBoolean("Auton Stage 6: Vision Tracking", true);
				//driveBase->DriveBackward(KRevsToScoreAuton, KAutonStraightSpeed); //TODO change values
				if(driveBase->GetTargetState() == true)
				{
					driveBase->SetTargetState(false); //we are now looking for the next target.
					driveBase->SetAutonStage(driveBase->KAutonFinished);	//move on to the third stage
					SmartDashboard::PutNumber("Leaving Auton Stage 6", driveBase->GetAutonStage());
				}
			}
#endif
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousRightSide::IsFinished() {
	if (driveBase->GetAutonStage() == driveBase->KAutonFinished && driveBase->GetTargetState() == true)
	{
//		SmartDashboard::PutBoolean("Auton Stage 4: Finished", true);
		driveBase->SetAutonStage(driveBase->KAutonNotStarted);
		return true;		//we are done with all stages of the autonomous
	}
	else
		return false;		//we may have finished some stages but not all.
}

// Called once after isFinished returns true
void AutonomousRightSide::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousRightSide::Interrupted() {

}
