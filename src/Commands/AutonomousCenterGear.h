#ifndef AutonomousCenterGear_H
#define AutonomousCenterGear_H

#include "../CommandBase.h"

class AutonomousCenterGear : public CommandBase {
public:
	AutonomousCenterGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousCenterGear_H
