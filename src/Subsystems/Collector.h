#ifndef SRC_SUBSYSTEMS_COLLECTOR_H_
#define SRC_SUBSYSTEMS_COLLECTOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

class Collector: public Subsystem
{
private:
	CANTalon* collectorMotor;

public:
	Collector();
	void InitDefaultCommand();
	void collectorOn();
	void collectorOff();
	void collectorSlow();
	void collectorOnReverse();

	const float KRampOn = 1;
	const float KRampOff = 0;
	const float KRampSlow = 0.6;
	const float KRampReverse = -1;

};

#endif /* SRC_SUBSYSTEMS_COLLECTORLIFT_H_ */
