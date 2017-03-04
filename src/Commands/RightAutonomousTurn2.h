#ifndef RightAutonomousTurn2_H
#define RightAutonomousTurn2_H

#include "../CommandBase.h"

class RightAutonomousTurn2 : public CommandBase {
public:
	RightAutonomousTurn2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RightAutonomousTurn2_H
