#ifndef FlywheelIncreaseSpeed_H
#define FlywheelIncreaseSpeed_H

#include "../CommandBase.h"

class FlywheelIncreaseSpeed : public CommandBase {
public:
	FlywheelIncreaseSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // FlywheelIncreaseSpeed_H
