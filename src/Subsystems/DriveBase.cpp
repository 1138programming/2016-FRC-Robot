#include "Subsystems/DriveBase.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/ShiftBase.h"
//#include "C:\Users\eeuser\wpilib\cpp\current\include\Talon.h"

//Drive Base Team: Gioia, Peter, Jahred and Kyle

DriveBase::DriveBase() :
 	frc::Subsystem("DriveBase")
{
	/* 4 Talons in the DriveBase, arranged in groups of 2. The front motors are the master motors, and the
	 *  rear motors are the followers. 2 Magnetic Encoders on the front motors. 2 DoubleSolenoids on the DriveBase.
	 *	One for the base and one for the Collector and Ratchet.
	 */
	//Sets up Right Motors
	RightFrontBaseMotor = new CANTalon(KRightBaseMaster); //RightFrontBase is the master Talon for the right side
	RightFrontBaseMotor->SetSafetyEnabled(true);

	RightRearBaseMotor = new CANTalon(KRightRearBaseTalon);
	RightRearBaseMotor->SetControlMode(CANTalon::kFollower); //RightRearBase is the follower to RightRearBase
	RightRearBaseMotor->Set(KRightBaseMaster);

	//Sets up Left motors
	//Left base motors are inverted
	LeftFrontBaseMotor = new CANTalon(KLeftBaseMaster); //LeftFrontBase is the master Talon on the Left side
	LeftFrontBaseMotor->SetSafetyEnabled(true);
	LeftFrontBaseMotor->SetInverted(true);

	LeftRearBaseMotor = new CANTalon(KLeftRearBaseTalon);
	LeftRearBaseMotor->SetControlMode(CANTalon::kFollower); //LeftRearBase is the follower to the LeftRearBase
	LeftRearBaseMotor->Set(KLeftBaseMaster);
	LeftRearBaseMotor->SetInverted(true);

	//Solenoids

	//0 is forward, 1 is reverse
	//LowGear is torque, HighGear is speed
	//forward = highgear; reverse = lowgear;
	ShiftSolenoid = new DoubleSolenoid(KShiftSolenoid1, KShiftSolenoid2);
	LiftSolenoid = new DoubleSolenoid(KLiftSolenoid1, KLiftSolenoid2);

	//Ultrasonic
	BaseUltrasonic = new Ultrasonic(1,1);
	BaseUltrasonic->SetAutomaticMode(true);

	//Gyro
	ahrs->GetYaw();

	//Encoders
	//Relative = Quadrature Encoder function of MagEncoder
	LeftFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	RightFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

	//LeftFrontBaseEncoder = new Encoder(0,1,false,Encoder::EncodingType::k4X);
}
void DriveBase::InitDefaultCommand()
{
	//SetDefaultCommand(new DriveWithJoysticks());
	//Sets the default to drive with joysticks when robot is turned on
	SetDefaultCommand(new DriveWithJoysticks());
}
void DriveBase::TankDrive(float left, float right)
{
	if(left > KDeadZoneLimit || left < -KDeadZoneLimit)
	{
		LeftRearBaseMotor->Set(left);
	}
	else
	{
		LeftRearBaseMotor->Set(0);
	}

	if(right > KDeadZoneLimit || right < -KDeadZoneLimit)
	{
		RightRearBaseMotor->Set(right);
	}
	else
	{
		RightRearBaseMotor->Set(0);
	}
}
void DriveBase::DriveForward(float distance, float speed)
{
	//LeftFrontBaseMotor->Reset();
	//RightFrontBaseMotor->Reset();
	LeftFrontBaseMotor->SetEncPosition(0);
	RightFrontBaseMotor->SetEncPosition(0);
	float encoder = LeftFrontBaseMotor->GetEncPosition();
	float encoder2 = RightFrontBaseMotor->GetEncPosition();
	while(encoder < distance && encoder2 < distance)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(speed);
		encoder = LeftFrontBaseMotor->GetEncPosition();
		encoder2 = RightFrontBaseMotor->GetEncPosition();
	}
	RightFrontBaseMotor->Set(0);	//turn off the motors once we reach the degrees
	LeftFrontBaseMotor->Set(0);
}
void DriveBase::DriveBackward(float speed, float distance)
{
	LeftFrontBaseMotor->SetEncPosition(0);
	RightFrontBaseMotor->SetEncPosition(0);
	float encoder = LeftFrontBaseMotor->GetEncPosition();
	float encoder2 = RightFrontBaseMotor->GetEncPosition();
	while(encoder > distance && encoder2 > distance)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(speed);
		encoder = LeftFrontBaseMotor->GetEncPosition();
		encoder2 = RightFrontBaseMotor->GetEncPosition();
	}
	RightFrontBaseMotor->Set(0);	//turn off the motors once we reach the degrees
	LeftFrontBaseMotor->Set(0);
}
void DriveBase::BaseTurnLeft(float speed, double degrees)
{
	ahrs->GetYaw();
	while(ahrs->GetAngleAdjustment() < degrees)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(-speed);
	}
	RightFrontBaseMotor->Set(0);	//turn off the motors once we reach the degrees
	LeftFrontBaseMotor->Set(0);
}

void DriveBase::BaseTurnRight(float speed, double degrees)
{
	while(ahrs->GetAngleAdjustment() < degrees)
	{
		RightFrontBaseMotor->Set(-speed);
		LeftFrontBaseMotor->Set(speed);
	}
	RightFrontBaseMotor->Set(0);	//turn off the motors once we reach the degrees
	LeftFrontBaseMotor->Set(0);
}

void DriveBase::StopBase()
{
	RightRearBaseMotor->Set(0);
	LeftRearBaseMotor->Set(0);
}

void DriveBase::HighShiftBase()
{
	ShiftSolenoid->Set(DoubleSolenoid::kForward);
}

void DriveBase::LowShiftBase()
{
	ShiftSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::ToggleShift()
{
	if(ShiftSolenoid -> Get() != DoubleSolenoid::kForward)
	{
		HighShiftBase();
	}
	else
	{
		LowShiftBase();
	}
}

void DriveBase::EngageLift()
{
	if(ShiftSolenoid->Get() != DoubleSolenoid::kReverse)
	{
		LowShiftBase();
		Wait(5);
		LiftSolenoid->Set(DoubleSolenoid::kForward);
	}
	else if(ShiftSolenoid->Get() == DoubleSolenoid::kForward)
	{
			LiftSolenoid->Set(DoubleSolenoid::kForward);
	}
}

void DriveBase::DisengageLift()
{
	LiftSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::InitDefaultCommandForUltrasonic()
{
	//bool IsEnabled = true;
}

void DriveBase::GetDistance()
{
	DistanceToGearCollector = BaseUltrasonic->GetRangeMM();
}


bool DriveBase::IsUltrasonicRangeValid()
{
	bool whatIsRange = BaseUltrasonic->IsRangeValid();
	SmartDashboard::PutNumber("UltrasonicInRange", (bool) whatIsRange);
	return whatIsRange;
}
