#include "Subsystems/Collector.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Collector::Collector() :

Subsystem("CollectorSubsystem")
{
	collectorMotor = new CANTalon(KCollectorTalon);
}

void Collector::InitDefaultCommand()
{

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

void Collector::StopCollector()
{

	collectorMotor->Set(0);

}
