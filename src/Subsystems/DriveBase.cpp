#include "Subsystems/DriveBase.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/ShiftBase.h"
#include "Commands/EngageLift.h"
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
	RightFrontBaseMotor->SetInverted(true);
	RightFrontBaseMotor->SetSafetyEnabled(true);
	RightFrontBaseMotor->EnableControl();


	RightRearBaseMotor = new CANTalon(KRightRearBaseTalon);
	RightRearBaseMotor->SetControlMode(CANTalon::kFollower); //RightRearBase is the follower to RightRearBase
	RightRearBaseMotor->Set(KRightFrontBaseTalon);
	RightRearBaseMotor->EnableControl();

	//Sets up Left motors
	//Left base motors are inverted
	LeftFrontBaseMotor = new CANTalon(KLeftFrontBaseTalon); //LeftFrontBase is the master Talon on the Left side
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
	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->GetYaw();

	//Encoders
	//Relative = Quadrature Encoder function of MagEncoder
	LeftFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	RightFrontBaseMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	LeftFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	RightFrontBaseMotor->ConfigEncoderCodesPerRev(4095);
	LeftFrontBaseMotor->SetEncPosition(0);
	RightFrontBaseMotor->SetEncPosition(0);

	//Variables for Ultrasonic

	DistanceToGearCollector = BaseUltrasonic->GetRangeMM();
	whatIsRange = BaseUltrasonic->IsRangeValid();
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
void DriveBase::DriveBackward(float speed, float distance)
{
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
	ShifterSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::LowShiftBase()
{
	ShifterSolenoid->Set(DoubleSolenoid::kForward);
}

int counter;

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
	counter++;
	SmartDashboard::PutNumber("CountyCountyCounty", (float)(counter) );
}
//kForward is lift engaged.
void DriveBase::EngageLift()
{
	if(LiftSolenoid->Get() == DoubleSolenoid::kForward) //is the lift engaged?
	{
		LiftSolenoid->Set(DoubleSolenoid::kReverse);	//disengage lift
		SmartDashboard::PutBoolean("lift engaged", false );
	}
	else
	{
			LiftSolenoid->Set(DoubleSolenoid::kForward);	//engage lift
			SmartDashboard::PutBoolean("lift engaged", true );
	}
}

void DriveBase::DisengageLift()
{
	LiftSolenoid->Set(DoubleSolenoid::kReverse);	//disengage lift
	if (LiftSolenoid->Get() == DoubleSolenoid::kReverse)
	{
		SmartDashboard::PutBoolean("lift engaged", false );
	}
}

void DriveBase::InitDefaultCommandForUltrasonic()
{

}

void DriveBase::GetDistance()
{
	DistanceToGearCollector = BaseUltrasonic->GetRangeMM();
}


bool DriveBase::IsUltrasonicRangeValid()
{
	whatIsRange = BaseUltrasonic->IsRangeValid();
	SmartDashboard::PutBoolean("UltrasonicInRange", whatIsRange);
	return whatIsRange;
}
