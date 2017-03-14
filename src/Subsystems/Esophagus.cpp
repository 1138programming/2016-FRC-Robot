#include "Esophagus.h"



Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{

	esophagusSolenoid = new DoubleSolenoid(KEsophagusSolenoid1, KEsophagusSolenoid2);

}

void Esophagus::InitDefaultCommand()
{

}

void Esophagus::ToggleEsophagus() //This function moves the Esophagus so that it can now collect gears
{
	if(esophagusSolenoid->Get() == DoubleSolenoid::kReverse) //If the esophagus is open...
	{
		esophagusSolenoid->Set(DoubleSolenoid::kForward); //...then close it
	}

	else //If closed...
	{
		esophagusSolenoid->Set(DoubleSolenoid::kReverse);	//...then open it
	}
}

