#ifndef RunCollectorWithJoysticks_H
#define RunCollectorWithJoysticks_H

#include "../CommandBase.h"

class RunCollectorWithJoysticks : public CommandBase {
public:
	RunCollectorWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunCollectorWithJoysticks_H
