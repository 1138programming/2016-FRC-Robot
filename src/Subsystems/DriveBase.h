#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "../RobotMap.h"

#include "C:\Users\eeuser\navx-mxp\cpp\include\AHRS.h"

#include "C:\Users\eeuser\wpilib\cpp\current\include\WPILib.h"
#include "C:\Users\eeuser\wpilib\user\cpp\include\CANTalon.h"
#include "c:\Users\eeuser\wpilib\cpp\current\include\Ultrasonic.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\SmartDashboard\SmartDashboard.h"


class DriveBase: public Subsystem
{
private:

	CANTalon* LeftRearBaseMotor; //Talon 1 in CAN Bus
	CANTalon* LeftFrontBaseMotor; //Talon 2 in CAN Bus
	CANTalon* RightRearBaseMotor; //Talon 3 in CAN Bus
	CANTalon* RightFrontBaseMotor; //Talon 4 in CAN Bus

	DoubleSolenoid* ShifterSolenoid;
	DoubleSolenoid* LiftSolenoid;

	//Gyro
	AHRS* ahrs;

	double waitPeriod = 5.00;

	Ultrasonic* BaseUltrasonic;
	double DistanceToGearCollector;
	bool whatIsRange;

public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive(float left, float right);
	void DriveForward(float speed, float distance);
	void DriveBackward(float speed, float distance);
	void BaseTurnLeft(float speed, double degrees);
	void BaseTurnRight(float speed, double degrees);
	void StopBase();
	void HighShiftBase();
	void LowShiftBase();
	void ToggleShift();

	void EngageLift();
	void DisengageLift();

	void InitDefaultCommandForUltrasonic();
	void GetDistance();
	bool IsUltrasonicRangeValid();


	const float KDeadZoneLimit = 0.1;

};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
