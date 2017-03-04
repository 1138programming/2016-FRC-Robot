#ifndef RightAutonomousTurn1_H
#define RightAutonomousTurn1_H

#include "../CommandBase.h"

class RightAutonomousTurn1 : public CommandBase {
public:
	RightAutonomousTurn1();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RightAutonomousTurn1_H
