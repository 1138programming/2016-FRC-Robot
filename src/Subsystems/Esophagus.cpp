#include <Subsystems/Esophagus.h>

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{
	// TODO Auto-generated constructor stub
	esophagusSingleSolenoid = new Solenoid(4);
}

void Esophagus::InitDefaultCommand()
{

}

void Esophagus::MoveEsophagusToGearCollection() //This function moves the Esophagus so that it can now collect gears
{
	esophagusSingleSolenoid->Set(false);
}

void Esophagus::MoveEsophagusToBallCollection() //This function moves the Esophagus so that it can now collect balls
{
	esophagusSingleSolenoid->Set(true);
}

void Esophagus::ShiftGearBallCollection() //This function moves the Esophagus so that it switches between collecting balls and gears
{
	esophagusSingleSolenoid->Get();
	if (esophagusSingleSolenoid)
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
	// TODO Auto-generated destructor stub
}
