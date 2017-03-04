#ifndef MoveBackwardUsingEncoder1_H
#define MoveBackwardUsingEncoder1_H

#include "../CommandBase.h"

class MoveBackwardUsingEncoder1 : public CommandBase {
public:
	MoveBackwardUsingEncoder1();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBackwardUsingEncoder1_H
