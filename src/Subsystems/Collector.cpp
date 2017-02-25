#include "Subsystems/Collector.h"
#include "Commands/CollectBallIntoStorage.h"
#include "Commands/DispenseBallOutOfStorage.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

Collector::Collector() :

Subsystem("CollectorSubsystem")
{
	collectorMotor = new CANTalon(9);
}

void Collector::InitDefaultCommand()
{

}

void Collector::collectorOn()
{
	collectorMotor->SetVoltageRampRate(KRampOn);
}

void Collector::collectorOff()
{
	collectorMotor->SetVoltageRampRate(KRampOff);
}

void Collector::collectorSlow()
{
	collectorMotor->SetVoltageRampRate(KRampSlow);
}

void Collector::collectorOnReverse()
{
	collectorMotor->SetVoltageRampRate(KRampReverse);
}
