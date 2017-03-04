#ifndef MoveBackwardUsingEncoder2_H
#define MoveBackwardUsingEncoder2_H

#include "../CommandBase.h"

class MoveBackwardUsingEncoder2 : public CommandBase {
public:
	MoveBackwardUsingEncoder2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBackwardUsingEncoder2_H
