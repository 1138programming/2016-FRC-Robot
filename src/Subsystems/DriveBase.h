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

	Encoder *LeftFrontBaseEncoder;
	Encoder *RightFrontBaseEncoder;

	AHRS* ahrs;

public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive(float left, float right);
	void DriveForward(float speed, float distance);
	void DriveBackward(float speed, float distance);
	void BaseTurnLeft(float speed, float degrees);
	void BaseTurnRight(float speed, float degrees);
	void StopBase();
	void HighShiftBase();
	void LowShiftBase();
	void ToggleShift();
	void EngageRatchet();
	void DisengageRatchet();

	const float KLeftMaster = 1; //KLeftMaster = Master Talon for left side
	const float KRightMaster = 3; //KRightMaster = Master Talon for right side

	const float KDeadZoneLimit = 0.1;

	const float KHighGear = (DoubleSolenoid::kForward);
	const float KLowGear = (DoubleSolenoid::kReverse);
};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
