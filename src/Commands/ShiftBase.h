#ifndef ShiftBase_H
#define ShiftBase_H

#include "../CommandBase.h"

class ShiftBase : public CommandBase {
public:
	ShiftBase();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShiftBase_H

