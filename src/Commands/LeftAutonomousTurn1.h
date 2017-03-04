#ifndef LeftAutonomousTurn1_H
#define LeftAutonomousTurn1_H

#include "../CommandBase.h"

class LeftAutonomousTurn1 : public CommandBase {
public:
	LeftAutonomousTurn1();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LeftAutonomousTurn1_H
