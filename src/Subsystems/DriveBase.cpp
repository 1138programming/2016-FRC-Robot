#include "Subsystems/DriveBase.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/ShiftBase.h"
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
	RightFrontBaseMotor = new CANTalon(KRightMaster); //RightFrontBase is the master Talon for the right side
	RightFrontBaseMotor->SetSafetyEnabled(true);

	RightRearBaseMotor = new CANTalon(2);
	RightRearBaseMotor->SetControlMode(CANTalon::kFollower); //RightRearBase is the follower to RightRearBase
	RightRearBaseMotor->Set(KRightMaster);

	//Sets up Left motors
	//Left base motors are inverted
	LeftFrontBaseMotor = new CANTalon(KLeftMaster); //LeftFrontBase is the master Talon on the Left side
	LeftFrontBaseMotor->SetSafetyEnabled(true);
	LeftFrontBaseMotor->SetInverted(true);

	LeftRearBaseMotor = new CANTalon(4);
	LeftRearBaseMotor->SetControlMode(CANTalon::kFollower); //LeftRearBase is the follower to the LeftRearBase
	LeftRearBaseMotor->Set(KLeftMaster);
	LeftRearBaseMotor->SetInverted(true);

	//Solenoids

	//0 is forward, 1 is reverse
	//LowGear is torque, HighGear is speed
	//forward = highgear; reverse = lowgear;
	BaseSolenoid = new DoubleSolenoid(0, 1);
	CollectorAndRatchetSolenoid = new DoubleSolenoid(2, 3);

	//Ultrasonic
	BaseUltrasonic = new Ultrasonic(1,1);
	BaseUltrasonic->SetAutomaticMode(true);

	//Gyro
	AHRS* ahrs = new AHRS();
	ahrs->GetYaw();

	//Encoders
	//Relative = Quadrature Encoder function of MagEncoder
	LeftFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	RightFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	LeftFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	RightFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	LeftFrontBaseMotor->SetEncPosition(0);
	RightFrontBaseMotor->SetEncPosition(0);

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
	//LeftFrontBaseMotor->SetEncPosition(0);
	//RightFrontBaseMotor->SetEncPosition(0);
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
void DriveBase::DriveBackward(float speed, float distance)
{
	//LeftFrontBaseMotor->SetEncPosition(0);
	//RightFrontBaseMotor->SetEncPosition(0);
	float encoderReference = LeftFrontBaseMotor->GetEncPosition();
	float encoder2Reference = RightFrontBaseMotor->GetEncPosition();
	float encoder = LeftFrontBaseMotor->GetEncPosition();
	float encoder2 = RightFrontBaseMotor->GetEncPosition();
	while((encoder - encoderReference) > distance && (encoder2 - encoder2Reference) > distance)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(speed);
		encoder = LeftFrontBaseMotor->GetEncPosition();
		encoder2 = RightFrontBaseMotor->GetEncPosition();
	}
}
void DriveBase::BaseTurnLeft(float speed, double degrees)
{
	ahrs->GetYaw();
	while(ahrs->GetAngleAdjustment() < degrees)
	{
		RightFrontBaseMotor->Set(speed);
		LeftFrontBaseMotor->Set(-speed);
	}
}
void DriveBase::BaseTurnRight(float speed, double degrees)
{
	while(ahrs->GetAngleAdjustment() < degrees)
	{
		RightFrontBaseMotor->Set(-speed);
		LeftFrontBaseMotor->Set(speed);
	}
}
void DriveBase::StopBase()
{
	RightRearBaseMotor->Set(0);
	LeftRearBaseMotor->Set(0);
}
void DriveBase::HighShiftBase()
{
	BaseSolenoid->Set(DoubleSolenoid::kForward);
}
void DriveBase::LowShiftBase()
{
	BaseSolenoid->Set(DoubleSolenoid::kReverse);
}
void DriveBase::ToggleShift()
{
	if(BaseSolenoid -> Get() != DoubleSolenoid::kForward)
	{
		HighShiftBase();
	}
	else
	{
		LowShiftBase();
	}
}
/*void DriveBase::ShiftBaseToCollector()
{
	CollectorAndRatchetSolenoid->Set(DoubleSolenoid::kForward);
}
void DriveBase::ShiftCollectorToBase()
{
	CollectorAndRatchetSolenoid->Set(DoubleSolenoid::kReverse);
}*/
void DriveBase::EngageLift()
{
	if(BaseSolenoid->Get() != DoubleSolenoid::kReverse)
	{
		LowShiftBase();
		Wait(5);
		CollectorAndRatchetSolenoid->Set(DoubleSolenoid::kForward);
	}
	else if(BaseSolenoid->Get() == DoubleSolenoid::kForward)
	{
			CollectorAndRatchetSolenoid->Set(DoubleSolenoid::kForward);
	}
}
void DriveBase::DisengageLift()
{
	CollectorAndRatchetSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::InitDefaultCommandForUltrasonic()
{
	bool IsEnabled = true;
}

void DriveBase::GetDistance()
{
	DistanceToGearCollector = BaseUltrasonic->GetRangeMM();
}


bool DriveBase::IsUltrasonicRangeValid()
{
	whatIsRange = BaseUltrasonic->IsRangeValid();
	SmartDashboard::PutNumber("UltrasonicInRange", (bool) whatIsRange);
}
