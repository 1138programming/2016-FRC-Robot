#ifndef RunFlywheels_H
#define RunFlywheels_H

#include "../CommandBase.h"

class RunFlywheels : public CommandBase {
public:
	RunFlywheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunFlywheels_H
