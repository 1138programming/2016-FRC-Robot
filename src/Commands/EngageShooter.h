#ifndef EngageShooter_H
#define EngageShooter_H

#include "../CommandBase.h"

class EngageShooter : public CommandBase {
public:
	EngageShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // EngageShooter_H
