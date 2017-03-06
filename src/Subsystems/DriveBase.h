#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "../RobotMap.h"

#include "C:\Users\eeuser\navx-mxp\cpp\include\AHRS.h"

#include "WPILib.h"
#include "CANTalon.h"
#include "Ultrasonic.h"
#include "SmartDashboard\SmartDashboard.h"


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
//	AHRS* ahrs;


	Ultrasonic* BaseUltrasonic;

public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive(float left, float right);
	void DriveForward(float distance, float speed);
	void DriveBackward(float distance, float speed);
	void BaseTurnLeft(double degrees, float speed);
	void BaseTurnRight(double degrees, float speed);
	void StopBase();
	void HighShiftBase();
	void LowShiftBase();
	void ToggleShift();

	void EngageLift();
//	void DisengageLift();

	void InitDefaultCommandForUltrasonic();
	double GetDistance();
	bool IsUltrasonicRangeValid();


	const float KDeadZoneLimit = 0;

};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
