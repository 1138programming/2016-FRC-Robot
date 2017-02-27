#ifndef SRC_SUBSYSTEMS_COLLECTOR_H_
#define SRC_SUBSYSTEMS_COLLECTOR_H_

#include "Commands/Subsystem.h"
#include "RobotMap.h"
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
	void CollectorForward(float collectorSpeedForward);
	void CollectorReverse(float collectorSpeedReverse);
	void CollectorDrive(float leftAxis, float rightAxis);
//	void CollectBallIntoStorage();
//	void DispenseBallOutOfStorage();
//	void StopCollector();

	const float KCollectorSpeedForward = 1;
	const float KCollectorSpeedReverse = -1;
	const float KCollectorSlowSpeed = 0.3;
	const float KCollectorSpeedStop = 0;
	const float KCollectorDeadZone = 0.1;
	const float KCollectorExtraSlowSpeed = 0.2;

	virtual ~Collector();
};

#endif /* SRC_SUBSYSTEMS_COLLECTORLIFT_H_ */
