/*
 * Shooter.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Wolf
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "WPILib.h"
#include "RobotMap.h"
#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "Encoder.h"

class Shooter: public frc::Subsystem {
private:

	CANTalon* collectorMotor;

	CANTalon* flywheelRight;
	CANTalon* flywheelLeft;

	CANTalon* filterFrontMotor;
	CANTalon* filterRearMotor;

	bool shooterState = false;
	int LastEncPosition = 0 ;
	int FlywheelSpeed =0 ;
	float FlywheelTargetSpeed = 1350;	//Initial target speed for the shooter.


public:
	Shooter();
	// To understand the override keyword in InitDefaultCommand(),
	// see http://stackoverflow.com/a/13880274
//	Return type	Command								Keywords
	void		InitDefaultCommand()				override;

	// Flywheel Control - Always send positive values; code will adjust as necessary
	void		FlywheelsOFF();
	void 		FlywheelsON(float speed) ;

	//Quadrature Functions
	double		GetEncPos();
	void		ResetEncPos();

	// Filter Control
	void FiltersOFF();
	void FlitersON();

	//Collector Control and status
//	void RunCollector(float speed);
//	void StopCollector();
	void SetShooterState(bool newState);
	float GetShooterSpeed();
	void AdjustShooterSpeed(float adjustment);
	bool SetShooterEngaged();
	bool SetShooterDisengaged();
	bool QueryShooterState();
	float GetShooterTargetSpeed();

	const float KShootSpeed = 1350;
	const float KFilterSpeed = 1;
	const int KTicksPerRotation = 4096.0;
	const int KUpdateInterval = 200.0;
	const float KMinFlywheelSpeed = 1000;
	const float KMaxFlywheelSpeed = 2000;
	const float KFlywheelSpeedAdjust = 20;	//speed adjustment per button press
};

#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
