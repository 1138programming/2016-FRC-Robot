#ifndef LeftAutonomousTurn2_H
#define LeftAutonomousTurn2_H

#include "../CommandBase.h"

class LeftAutonomousTurn2 : public CommandBase {
public:
	LeftAutonomousTurn2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LeftAutonomousTurn2_H
