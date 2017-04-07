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
	float encoderLeft = 0;
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
	int GetAutonStage();		//keeps track of where we are in multi-stage auton (turn left and right)
	void SetAutonStage(int stage);
	float GetEncoderReference();
	void SetEncoderReference();
	float GetLeftEncoderReference();

	void SetLeftEncoderReference();

	void EngageLift();
//	void DisengageLift();

	void InitDefaultCommandForUltrasonic();
	double GetDistance();
	bool IsUltrasonicRangeValid();
	bool targetstate = false;
	int autonstage = 0;		//not currently doing auton stage
	float encrefposition = 0;		//this is used to remember an encoder position
	float encrefpositionLeft = 0;

	const int KAutonNotStarted = 0;	//haven't started the auton
	const int KAutonFirstMove = 1;	//we are moving forward the first time.
	const int KAutonTurn	= 2;	//we are doing the turn (left or right)
	const int KAutonSecondMove = 3; //we are moving forward to the peg.
	const int KAutonVision1 = 4;		//only used if we have the vision tracking, but it can stay here
	const int KAutonVision2 = 5;		//only used if we have the vision tracking, but it can stay here
	const int KAutonVision3 = 6;		//only used if we have the vision tracking, but it can stay here
	const int KAutonFinished = 7;	//completed all stages of the autonomous

};

#endif /* SRC_SUBSYSTEMS_BASE_H_ */
