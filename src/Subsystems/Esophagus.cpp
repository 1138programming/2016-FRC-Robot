#include <Subsystems/Esophagus.h>
#include "C:\Users\eeuser\wpilib\cpp\current\include\Solenoid.h"
#include "Commands/EsophagusToBallCollection.h"
#include "Commands/EsophagusToGearCollection.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Esophagus::Esophagus() :

Subsystem("EsophagusSubsystem")
{
	// TODO Auto-generated constructor stub
	esophagusSolenoid = new DoubleSolenoid(4, 5);
}

void Esophagus::InitDefaultCommand()
{

}

void Esophagus::MoveEsophagusToGearCollection() //This function moves the Esophagus so that it can now collect gears
{
	esophagusSolenoid->Set(DoubleSolenoid::kReverse);
}

void Esophagus::MoveEsophagusToBallCollection() //This function moves the Esophagus so that it can now collect balls
{
	esophagusSolenoid->Set(DoubleSolenoid::kForward);
}

void Esophagus::ShiftGearBallCollection() //This function moves the Esophagus so that it switches between collecting balls and gears
{
	if (esophagusSolenoid->Get() = DoubleSolenoid::kForward) //If the Solenoid is set to Ball Collection
		{
			MoveEsophagusToGearCollection(); //Then it will change to gear collection
		}
		else //otherwise
		{
			MoveEsophagusToBallCollection(); //it will change to ball collection
		}
}
