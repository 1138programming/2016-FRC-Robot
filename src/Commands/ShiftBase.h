#ifndef ShiftBase_H
#define ShiftBase_H

#include "../CommandBase.h"

class ShiftBase: public CommandBase {
public:
	ShiftBase();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif
