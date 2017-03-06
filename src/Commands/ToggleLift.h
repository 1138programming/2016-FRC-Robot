#ifndef ToggleLift_H
#define ToggleLift_H

#include "../CommandBase.h"

class ToggleLift : public CommandBase {
public:
	ToggleLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleLift_H
