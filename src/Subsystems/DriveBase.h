#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"
#include "AHRS.h"

class DriveBase: public Subsystem
{
private:

	CANTalon* LeftRearBaseMotor; //Talon 1 in CAN Bus
	CANTalon* LeftFrontBaseMotor; //Talon 2 in CAN Bus
	CANTalon* RightRearBaseMotor; //Talon 3 in CAN Bus
	CANTalon* RightFrontBaseMotor; //Talon 4 in CAN Bus

	DoubleSolenoid* BaseSolenoid;
	DoubleSolenoid* CollectorAndRatchetSolenoid;

	//Encoder *LeftFrontBaseEncoder;
	//Encoder *RightFrontBaseEncoder;

	//Gyro
	AHRS* ahrs;

	//PIDController
	PIDController* turnController;


public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive(float left, float right);
	void DriveForward(float speed, float distance);
	void DriveBackward(float speed, float distance);
	void BasePointTurnLeftWithGyro(float speed, float angleAdjustment);
	void BasePointTurnRightWithGyro(float speed, float angleAdjustment);
	void BaseRoundTurnLeftWithGyro(float fastWheelSpeed, float slowWheelSpeed, float degrees);
	void BaseRoundTurnRightWithGyro(float fastWheelSpeed, float slowWheelSpeed, float degrees);
	void StopBase();
	void HighShiftBase();
	void LowShiftBase();
 	void ToggleShift();
	void EngageLift();
	void DisengageLift();

	const float KLeftMaster = 1; //KLeftMaster = Master Talon for left side
	const float KRightMaster = 3; //KRightMaster = Master Talon for right side

	const float KDeadZoneLimit = 0.1;

	const float KHighGear = (DoubleSolenoid::kForward);
	const float KLowGear = (DoubleSolenoid::kReverse);

	const static double kP = 0.03f;
	const static double kI = 0.00f;
	const static double kD = 0.00f;
	const static double kF = 0.00f;
	const static double kToleranceDegrees = 2.0f;
};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
