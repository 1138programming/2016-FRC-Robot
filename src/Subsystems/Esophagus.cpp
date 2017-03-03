#include "Esophagus.h"



Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{

	esophagusSolenoid = new DoubleSolenoid(KEsophagusSolenoid1, KEsophagusSolenoid2);

}

void Esophagus::InitDefaultCommand()
{
	SmartDashboard::PutNumber("Three", 3.0);
	//MoveEsophagusToGearCollection();
}

void Esophagus::MoveEsophagusToGearCollection() //This function moves the Esophagus so that it can now collect gears
{

	if(esophagusSolenoid->Get() != DoubleSolenoid::kForward)
	{
		esophagusSolenoid->Set(DoubleSolenoid::kForward);
	}

}

void Esophagus::MoveEsophagusToBallCollection() //This function moves the Esophagus so that it can now collect balls
{

	if(esophagusSolenoid->Get() != DoubleSolenoid::kReverse)
	{
		esophagusSolenoid->Set(DoubleSolenoid::kReverse);
	}
}

