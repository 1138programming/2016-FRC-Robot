#ifndef AutonomousLeftSide_H
#define AutonomousLeftSide_H

#include "../CommandBase.h"
#include "../RobotMap.h"

class AutonomousLeftSide : public CommandBase {
public:
	AutonomousLeftSide();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousLeftSide_H
