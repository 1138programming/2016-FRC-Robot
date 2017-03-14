/*
        * Shooter.cpp
 *
 *
 */

#include <Subsystems/Shooter.h>
#include "CANTalon.h"
#include "Commands/EngageShooter.h"
#include "Commands/DisengageShooter.h"
#include "Commands/FiltersOn.h"
#include "Commands/FiltersOff.h"
#include "Commands/FlywheelDecreaseSpeed.h"
#include "Commands/FlywheelIncreaseSpeed.h"
#include "Commands/FlywheelsOff.h"
#include "Commands/RunFlywheels.h"
/*
 *
 */

Shooter::Shooter() :

frc::Subsystem("ShooterSubsystem")
{
	/*
	 *  Initialize talons used by Shooter subsystem
	 */

	flywheelLeft = new CANTalon(KFlywheelLeftTalon);
	flywheelRight = new CANTalon(KFlywheelRightTalon);

	// Make the left talon both inverted and enable control
	flywheelLeft->EnableControl();
	flywheelLeft->SetSafetyEnabled(false);
	flywheelLeft->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	//flywheelRight->SetInverted(true);

	flywheelRight->SetControlMode(CANTalon::kFollower);
	flywheelRight->Set(KFlywheelLeftTalon);
	flywheelRight->SetClosedLoopOutputDirection(true); //flywheel right is inverted relative to the master


	// Zero out quadrature encoder
	flywheelLeft->SetPosition(0);

	filterFrontMotor = new CANTalon(KFilterFrontTalon);
	filterRearMotor = new CANTalon(KFilterRearTalon);

	// Make the left filter inverted, and enable control
	filterFrontMotor->EnableControl();
	filterFrontMotor->SetSafetyEnabled(false);
	filterFrontMotor->SetInverted(true);

	// Make the rear talon a slave to the front one
	filterRearMotor->SetControlMode(CANTalon::kFollower);
	filterRearMotor->Set(KFilterFrontTalon);

	//bool shooterState = false;

	//const float KTargetFlywheelSpeed = 1 ;
}

void Shooter::InitDefaultCommand()
{
}

void Shooter::FlywheelsON(float speed)
{
	flywheelLeft->Set(speed);
}

void Shooter::FlywheelsOFF()
{
	flywheelLeft->Set(0);
}

double Shooter::GetEncPos() {
	return flywheelLeft->GetPosition();
}

void Shooter::ResetEncPos() {
	flywheelLeft->SetPosition(0);
}

void Shooter::FlitersON()
{
	filterFrontMotor->Set(KFilterSpeed);
}

void Shooter::FiltersOFF()
{
	filterFrontMotor->Set(0);
}

bool Shooter::SetShooterEngaged()
{
	shooterState = true;
	return shooterState;
}

bool Shooter::SetShooterDisengaged()
{
	shooterState = false;
	return shooterState;
}

bool Shooter::QueryShooterState()
{
	SmartDashboard::PutBoolean("query shooter state", shooterState);
	return Shooter::shooterState;
}

void Shooter::SetShooterState(bool newState)
{
	shooterState = newState;
}

float Shooter::GetShooterSpeed()
{
	FlywheelSpeed = (KUpdateInterval / KTicksPerRotation) * (Shooter::flywheelLeft->GetEncPosition() - LastEncPosition);

	return FlywheelSpeed ;
}

//Pass in a value to adjust the shooter target speed.  Check that you are not exceeding the limits
void Shooter::AdjustShooterSpeed(float adjustment)
{
	if(adjustment < 0 && FlywheelTargetSpeed + adjustment >= KMinFlywheelSpeed)	//decreasing, but not below the minimum
	{
		FlywheelTargetSpeed += adjustment;
	}
	else if(adjustment > 0 && FlywheelTargetSpeed + adjustment <= KMaxFlywheelSpeed) //increasing, but not above the minimum
	{
		FlywheelTargetSpeed += adjustment;
	}
}

float Shooter::GetShooterTargetSpeed()
{
	return FlywheelSpeed;
}

