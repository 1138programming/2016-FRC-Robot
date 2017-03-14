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

	const float KcollectorSpeedSLOW = 0.2;	//a very slow speed for adjusting the collector when trying to catch the knot for a lift
};

#endif  // RunCollectorWithJoysticks_H
