#ifndef EngageLift_H
#define EngageLift_H

#include "../CommandBase.h"

class EngageLift : public CommandBase {
public:
	EngageLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // EngageLift_H
