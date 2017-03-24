#ifndef AutonomousLineDrive_H
#define AutonomousLineDrive_H

#include "../CommandBase.h"

class AutonomousLineDrive : public CommandBase {
public:
	AutonomousLineDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousLineDrive_H
