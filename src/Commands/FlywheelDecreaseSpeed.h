#ifndef FlywheelDecreaseSpeed_H
#define FlywheelDecreaseSpeed_H

#include "../CommandBase.h"

class FlywheelDecreaseSpeed : public CommandBase {
public:
	FlywheelDecreaseSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // FlywheelDecreaseSpeed_H
