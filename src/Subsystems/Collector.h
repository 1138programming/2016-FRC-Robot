#ifndef SRC_SUBSYSTEMS_COLLECTOR_H_
#define SRC_SUBSYSTEMS_COLLECTOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

class Collector: public Subsystem
{
private:
	CANTalon* collectorCIM;

public:
	Collector();
	void InitDefaultCommand();
	void CollectBallIntoStorage();
	void DispenseBallOutOfStorage();
	void StopCollector();

	const float KCollectorSpeedForward = 1;
	const float KCollectorSpeedReverse = -1;
	const float KCollectorSpeedStop = 0;
};

#endif /* SRC_SUBSYSTEMS_COLLECTORLIFT_H_ */
