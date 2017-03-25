#ifndef AutonomousRightSide_H
#define AutonomousRightSide_H

#include "../CommandBase.h"
#include "../RobotMap.h"

class AutonomousRightSide : public CommandBase {
public:
	AutonomousRightSide();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousRightSide_H
