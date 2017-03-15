#include "Collector.h"
#include "../RobotMap.h"
#include "Commands/RunCollectorWithJoysticks.h"
#include "Commands/RunCollectorForShooter.h"

Collector::Collector() : Subsystem("ExampleSubsystem")
{
	collectorMotor = new CANTalon(KCollectorTalon);
}

void Collector::InitDefaultCommand()
{
	SetDefaultCommand(new RunCollectorWithJoysticks());
}


void Collector::StopCollector() //This function makes the collector stop moving
{
	collectorMotor->Set(0);

}

void Collector::RunCollector(float speed)
{
	SmartDashboard::PutNumber("Running the collector at speed ", speed);
	collectorMotor->Set(speed);
}
