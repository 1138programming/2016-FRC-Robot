#ifndef SRC_SUBSYSTEMS_ESOPHAGUS_H_
#define SRC_SUBSYSTEMS_ESOPHAGUS_H_

//Esophagus subsystem: Connor N, Christian G, and Chris H(A little)

#include "WPILib.h"
#include "Commands/Subsystem.h"

class Esophagus: public Subsystem
{
private:
	Solenoid* esophagusSingleSolenoid;


public:
	Esophagus();
	void InitDefaultCommand();
	void MoveEsophagusToGearCollection();
	void MoveEsophagusToBallCollection();
	void ShiftGearBallCollection();
};

#endif /* SRC_SUBSYSTEMS_ESOPHAGUS_H_ */
