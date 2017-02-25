#include "../Subsystems/Esophagus.h"

Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{
	// TODO Auto-generated constructor stub
	esophagusSolenoid = new DoubleSolenoid(4,5);
}

void Esophagus::InitDefaultCommand()
{

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

