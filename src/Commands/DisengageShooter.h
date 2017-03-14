#ifndef DisengageShooter_H
#define DisengageShooter_H

#include "../CommandBase.h"

class DisengageShooter : public CommandBase {
public:
	DisengageShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DisengageShooter_H
