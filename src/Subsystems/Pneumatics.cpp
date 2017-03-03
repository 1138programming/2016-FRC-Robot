#include <Subsystems/Pneumatics.h>
#include "../RobotMap.h"

Pneumatics::Pneumatics() :
		Subsystem("Pneumatics")
{
	pCompressor = new Compressor(0);

	pressureSensor = new AnalogInput(0);
//	lw->AddSensor("Pneumatics", "pressureSensor", pneumaticspressureSensor);
}

void Pneumatics::InitDefaultCommand()
{
	//pCompressor->Start();
}
