#ifndef Collector_H
#define Collector_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"

class Collector : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Collector();
	void InitDefaultCommand();

	CANTalon* collectorMotor;

	void StopCollector();
	void RunCollector(float speed);

	const float KCollectorSpeedForward = 1;
	const float KCollectorSpeedReverse = -1;
	const float KCollectorSlowSpeed = 0.15;
	const float KCollectorSpeedStop = 0;
};

#endif  // Collector_H
