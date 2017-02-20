#ifndef SRC_SUBSYSTEMS_PNEUMATICS_H_
#define SRC_SUBSYSTEMS_PNEUMATICS_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pneumatics: public Subsystem
{
private:
	Compressor* pCompressor;

	AnalogInput* pressureSensor;

public:
	Pneumatics();
	void InitDefaultCommand();
};

#endif /* SRC_SUBSYSTEMS_PNEUMATICS_H_ */
