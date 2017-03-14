#ifndef RunCollectorForShooter_H
#define RunCollectorForShooter_H

#include "../CommandBase.h"

class RunCollectorForShooter : public CommandBase {
public:
	RunCollectorForShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunCollectorForShooter_H
