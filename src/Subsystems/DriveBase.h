#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "../RobotMap.h"

#include "AHRS.h"

#include "WPILib.h"
#include "CANTalon.h"
#include "Ultrasonic.h"

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
	AHRS* gyroAccelerometer;
	float encoder = 0;

	Ultrasonic* BaseUltrasonic;

public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive(float left, float right);
	void DriveForward(float distance, float speed);
	void DriveBackward(float distance, float speed);
	void TurnWithBase(double degrees, float turnspeed, bool leftturn);
	void StopBase();
	void HighShiftBase();
	void LowShiftBase();
	void ToggleShift();
	void ResetEncoders();
	int QueryLiftState();
	bool GetTargetState();	//specifies whether or not we are looking for a target
	void SetTargetState(bool state);
	void ResetGyro();

	void EngageLift();
//	void DisengageLift();

	void InitDefaultCommandForUltrasonic();
	double GetDistance();
	bool IsUltrasonicRangeValid();
	bool targetstate = false;

	//autonomous turn constant right and left 1 and 2
	//If in left, turn left, forward, right
};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
