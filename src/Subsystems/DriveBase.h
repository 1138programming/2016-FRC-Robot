#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DriveBase: public Subsystem
{
private:

	CANTalon* LeftRearBaseMotor; //Talon 1 in CAN Bus
	CANTalon* LeftFrontBaseMotor; //Talon 2 in CAN Bus
	CANTalon* RightRearBaseMotor; //Talon 3 in CAN Bus
	CANTalon* RightFrontBaseMotor; //Talon 4 in CAN Bus

	DoubleSolenoid* LeftBaseSolenoid;
	DoubleSolenoid* RightBaseSolenoid;
	DoubleSolenoid* LeftCollectorSolenoid;
	DoubleSolenoid* RightCollectorSolenoid;
	DoubleSolenoid* RatchetSolenoid;

	Encoder* LeftRearBaseEncoder;
	Encoder* RightRearBaseEncoder;

public:
	DriveBase();
	void InitDefaultCommand();
	void TankDrive();
	void DriveForward(float distance, float speed);
	void DriveBackward();
	void BaseTurnLeft();
	void BaseTurnRight();
	void StopBase();
	void UpShiftBase();
	void DownShiftBase();
	void ShiftBaseToCollector();
	void ShiftCollectorToBase();
	void EngageRatchet();
	void DisengageRatchet();
	void ToggleShift();

	const float KLeftMaster = 1; //KLeftMaster = Master Talon for left side
	const float KRightMaster = 3; //KRightMaster = Master Talon for right side

};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
