#include "Subsystems/Collector.h"
#include "Commands/RunCollectorWithJoysticks.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Collector::Collector() :

Subsystem("CollectorSubsystem")
{
	collectorMotor = new CANTalon(KCollectorTalon);
}

void Collector::InitDefaultCommand()
{
	SetDefaultCommand(new RunCollectorWithJoysticks());
}

void Collector::CollectorForward(float collectorSpeedForward)
{
	collectorMotor->Set(collectorSpeedForward);
}

void Collector::CollectorReverse(float collectorSpeedReverse)
{
	collectorMotor->Set(collectorSpeedReverse);
}

void Collector::CollectorDrive(float leftAxis, float rightAxis)
{
	/*Joystick values are passed in when called.
	if outside deadzone, run collector with left value
	else if right outside deadzone, run collector with right value
	else do not run, turn off collector*/

	//XBox Axis are reversed in the OI
	if(leftAxis > KCollectorDeadZone || leftAxis < -KCollectorDeadZone)
	{
		collectorMotor->Set(leftAxis);
	}
	else if(rightAxis > KCollectorDeadZone)
	{
		collectorMotor->Set(KCollectorExtraSlowSpeed);
	}
	else if(rightAxis < -KCollectorDeadZone)
	{
		collectorMotor->Set(-KCollectorExtraSlowSpeed);
	}
	else
	{
		collectorMotor->Set(KCollectorSpeedStop);
	}
}

//void Collector::CollectBallIntoStorage() //This function makes the collector collect the balls into the storage.
//{
//	collectorCIM->Set(KCollectorSpeedForward);
//}
//
//void Collector::DispenseBallOutOfStorage() //This function makes the collector dispense the balls out of the storage.
//{
//	collectorCIM->Set(KCollectorSpeedForward);
//}

//void Collector::StopCollector() //This function makes the collector stop moving
//{
//	collectorCIM->Set(KCollectorSpeedStop);
//}

Collector::~Collector()
{
	// TODO Auto-generated destructor stub
}
