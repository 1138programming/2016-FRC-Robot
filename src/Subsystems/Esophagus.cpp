#include "Subsystems/Esophagus.h"
#include "WPILib.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{

	esophagusSolenoid = new DoubleSolenoid(KEsophagusSolenoid1, KEsophagusSolenoid2);
}

void Esophagus::InitDefaultCommand()
{
	MoveEsophagusToGearCollection();
}

void Esophagus::MoveEsophagusToGearCollection() //This function moves the Esophagus so that it can now collect gears
{
	esophagusSolenoid->Set(DoubleSolenoid::kOff);;
}

void Esophagus::MoveEsophagusToBallCollection() //This function moves the Esophagus so that it can now collect balls
{
	esophagusSolenoid->Set(DoubleSolenoid::kForward);;
}

void Esophagus::ShiftGearBallCollection() //This function moves the Esophagus so that it switches between collecting balls and gears
{
		if (esophagusSolenoid->Get() == DoubleSolenoid::kForward)
		{
			MoveEsophagusToGearCollection();
		}
		else
		{
			MoveEsophagusToBallCollection();
		}
}

Esophagus::~Esophagus()
{

}
