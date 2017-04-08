#include "Esophagus.h"
#include "Commands/OpenEsophagus.h"
#include "Commands/CloseEsophagus.h"


Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{

	esophagusSolenoid = new DoubleSolenoid(KEsophagusSolenoid1, KEsophagusSolenoid2);

}

void Esophagus::InitDefaultCommand()
{

}
void Esophagus::closeEsophagus()
{
//	SmartDashboard::PutBoolean("About to close the Esophagus", true);
//	if(esophagusSolenoid->Get() == DoubleSolenoid::kReverse)
//	{
//		SmartDashboard::PutBoolean("Closing Esophagus", true);
		esophagusSolenoid->Set(DoubleSolenoid::kForward);
//	}
//	else
//	{
//		esophagusSolenoid->Set(DoubleSolenoid::kReverse);
//	}
}

void Esophagus::OpenEsophagus()
{
//	SmartDashboard::PutBoolean("About to open the Esophagus", true);
//	if(esophagusSolenoid->Get() == DoubleSolenoid::kForward)	//pb vegas
//	{															//pb vegas
//		SmartDashboard::PutBoolean("Opening Esophagus", true);
		esophagusSolenoid->Set(DoubleSolenoid::kReverse);
//	}															//pb vegas
}

void Esophagus::ToggleEsophagus() //This function moves the Esophagus so that it can now collect gears
{
	 if(esophagusSolenoid->Get() == DoubleSolenoid::kReverse)	//if it is open
	{
		esophagusSolenoid->Set(DoubleSolenoid::kForward); //...then close it
	}

	else if(esophagusSolenoid->Get() == DoubleSolenoid::kForward) //If closed...
	{
		esophagusSolenoid->Set(DoubleSolenoid::kReverse);	//...then open it
	}
}


