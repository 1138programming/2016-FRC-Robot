#include "Subsystems/DriveBase.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/MoveBackwardWithEncoders.h"
#include "Commands/TurnToFacePilotTower.h"
#include "Commands/ShiftBase.h"
#include "Commands/ToggleLift.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\Talon.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\Solenoid.h"
#include "sys/wait.h"


//Drive Base Team: Gioia, Peter, Jahred and Kyle
DriveBase::DriveBase() :
 	 Subsystem("DriveBase")
{
	/* 4 Talons in the DriveBase, arranged in groups of 2. The front motors are the master motors, and the
	 *  rear motors are the followers. 2 Magnetic Encoders on the front motors. 2 DoubleSolenoids on the DriveBase.
	 *	One for the base and one for the Collector and Ratchet.
	 */
	//Sets up Right Motors
	RightFrontBaseMotor = new CANTalon(KRightFrontBaseTalon); //RightFrontBase is the master Talon for the right side
//	RightFrontBaseMotor->SetInverted(true);
	RightFrontBaseMotor->SetSafetyEnabled(true);
	RightFrontBaseMotor->EnableControl();


	RightRearBaseMotor = new CANTalon(KRightRearBaseTalon);
	RightRearBaseMotor->SetControlMode(CANTalon::kFollower); //RightRearBase is the follower to RightRearBase
	RightRearBaseMotor->Set(KRightFrontBaseTalon);
	RightRearBaseMotor->EnableControl();

	//Sets up Left motors
	//Left base motors are inverted
	LeftFrontBaseMotor = new CANTalon(KLeftFrontBaseTalon); //LeftFrontBase is the master Talon on the Left side
	LeftFrontBaseMotor->SetInverted(true);
	LeftFrontBaseMotor->SetSafetyEnabled(true);
	LeftFrontBaseMotor->EnableControl();

	LeftRearBaseMotor = new CANTalon(KLeftRearBaseTalon);
	LeftRearBaseMotor->SetControlMode(CANTalon::kFollower); //LeftRearBase is the follower to the LeftRearBase
	LeftRearBaseMotor->Set(KLeftFrontBaseTalon);


	//Solenoids

	//0 is forward, 1 is reverse
	//LowGear is torque, HighGear is speed
	//forward = highgear; reverse = lowgear;
	ShifterSolenoid = new DoubleSolenoid(KShifterSolenoid1, KShifterSolenoid2);
	LiftSolenoid = new DoubleSolenoid(KLiftSolenoid1, KLiftSolenoid2);

	//Ultrasonic
	BaseUltrasonic = new Ultrasonic(KBaseUltrasonic1, KBaseUltrasonic2);
	BaseUltrasonic->SetAutomaticMode(true);

	//Gyro
	gyroAccelerometer = new AHRS(SPI::Port::kMXP);
	gyroAccelerometer->AHRS::ZeroYaw();


	//Encoders
	//Relative = Quadrature Encoder function of MagEncoder
	LeftFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	RightFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	LeftFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	RightFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	LeftFrontBaseMotor->SetEncPosition(0);
	RightFrontBaseMotor->SetEncPosition(0);

	//Variables for Ultrasonic

}

void DriveBase::InitDefaultCommand()
{
	//Sets the default to drive with joysticks when robot is turned on
	SetDefaultCommand(new DriveWithJoysticks());
}

void DriveBase::TankDrive(float left, float right)
{
	if(left > KDeadZoneLimit || left < -KDeadZoneLimit)
	{
		LeftFrontBaseMotor->Set(left);
		SmartDashboard::PutNumber("leftjoystick", left);
	}
	else
	{
		LeftFrontBaseMotor->Set(0);
	}

	if(right > KDeadZoneLimit || right < -KDeadZoneLimit)
	{
		RightFrontBaseMotor->Set(right);
		SmartDashboard::PutNumber("rightjoystick", right);
	}
	else
	{
		RightFrontBaseMotor->Set(0);
	}
}

void DriveBase::DriveForward(float distance, float speed)
{
	float encoderReference = LeftFrontBaseMotor->GetEncPosition();
	float encoder2Reference = RightFrontBaseMotor->GetEncPosition();
	float encoder = LeftFrontBaseMotor->GetEncPosition();
	float encoder2 = RightFrontBaseMotor->GetEncPosition();
	while((encoder - encoderReference) < distance && (encoder2 - encoder2Reference) < distance)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(speed);
		encoder = LeftFrontBaseMotor->GetEncPosition();
		encoder2 = RightFrontBaseMotor->GetEncPosition();
	}
}
void DriveBase::DriveBackward(float distance, float speed)
{
	SmartDashboard::PutNumber("Distance To Pilot Tower", KDistanceToPilotTower);
	SmartDashboard::PutNumber("Distance To Base Line", KDistanceToBaseLine);
	float encoderReference = LeftFrontBaseMotor->GetEncPosition();
	float encoder2Reference = RightFrontBaseMotor->GetEncPosition();
	float encoder = LeftFrontBaseMotor->GetEncPosition();
	float encoder2 = RightFrontBaseMotor->GetEncPosition();
	while((encoder - encoderReference) > distance*4096 && (encoder2 - encoder2Reference) > distance)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(speed);
		encoder = LeftFrontBaseMotor->GetEncPosition();
		encoder2 = RightFrontBaseMotor->GetEncPosition();
	}
}
void DriveBase::TurnWithBase(double degrees, float turnspeed, bool leftturn)
{
	if(gyroAccelerometer->IsCalibrating() != true && gyroAccelerometer->IsConnected() == true)
	{
		double targetangle;
		SmartDashboard::PutBoolean("Is Left Turn True?", leftturn);
		if(leftturn) //Make a left turn if true
		{
			//Set targetangle to target value, degrees is negative because of turning left
			targetangle = -degrees + gyroAccelerometer->GetAngle();
			SmartDashboard::PutNumber("Target Angle", targetangle);
			while(targetangle <= gyroAccelerometer->GetAngle()) //While has not reached target value
			{
				//Keep turning to target
				SmartDashboard::PutNumber("Current Angle Value", gyroAccelerometer->GetAngle());
				RightFrontBaseMotor->Set(turnspeed);
				LeftFrontBaseMotor->Set(-turnspeed);
			}
			//Turn off the base motors
			RightFrontBaseMotor->Set(0);
			LeftFrontBaseMotor->Set(0);
		}
		else //Make a right turn if false
		{
			//Set targetangle to target value, degrees is positive because of turning right
			targetangle = degrees + gyroAccelerometer->GetAngle();
			SmartDashboard::PutNumber("Target Angle", targetangle);
			while(targetangle >= gyroAccelerometer->GetAngle()) //While has not reached target value
			{
				//Keep turning to target
				SmartDashboard::PutNumber("Current Angle Value", gyroAccelerometer->GetAngle());
				RightFrontBaseMotor->Set(-turnspeed);
				LeftFrontBaseMotor->Set(turnspeed);
			}
			//Turn off the base motors
			RightFrontBaseMotor->Set(0);
			LeftFrontBaseMotor->Set(0);
		}
	}
}

void DriveBase::StopBase()
{
	RightRearBaseMotor->Set(0);
	LeftRearBaseMotor->Set(0);
}

void DriveBase::HighShiftBase()
{
	ShifterSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::LowShiftBase()
{
	ShifterSolenoid->Set(DoubleSolenoid::kForward);
}

void DriveBase::ToggleShift()
{
	if(ShifterSolenoid -> Get() == DoubleSolenoid::kForward) //is it in low gear?
	{
		HighShiftBase();		//put it in high gear
	}
	else
	{
		LowShiftBase();
	}
}

void DriveBase::EngageLift()
{
	if(LiftSolenoid->Get() == DoubleSolenoid::kForward) //is the lift engaged?
	{
		LiftSolenoid->Set(DoubleSolenoid::kReverse);	//disengage lift
	}
	else
	{
		LiftSolenoid->Set(DoubleSolenoid::kForward);	//engage lift
	}
}

//void DriveBase::DisengageLift()
//{
//	LiftSolenoid->Set(DoubleSolenoid::kReverse);	//disengage lift
//}

void DriveBase::InitDefaultCommandForUltrasonic()
{

}

double DriveBase::GetDistance()
{
	SmartDashboard::PutNumber("DistanceMM", BaseUltrasonic->GetRangeMM()) ;
	return BaseUltrasonic->GetRangeMM();
}


bool DriveBase::IsUltrasonicRangeValid()
{
	SmartDashboard::PutBoolean("UltrasonicInRange", BaseUltrasonic->IsRangeValid());
	return BaseUltrasonic->IsRangeValid();
}
