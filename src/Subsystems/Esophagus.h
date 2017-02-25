#ifndef SRC_SUBSYSTEMS_ESOPHAGUS_H_
#define SRC_SUBSYSTEMS_ESOPHAGUS_H_

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "Solenoid.h"

class Esophagus: public Subsystem
{
private:
	DoubleSolenoid* esophagusSolenoid;

public:
	Esophagus();
	void InitDefaultCommand();
	void MoveEsophagusToGearCollection();
	void MoveEsophagusToBallCollection();
	void MoveEsophagus();
//	void ShiftGearBallCollection();
};

#endif /* SRC_SUBSYSTEMS_ESOPHAGUS_H_ */
