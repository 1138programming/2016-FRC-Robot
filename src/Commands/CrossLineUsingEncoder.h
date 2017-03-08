#ifndef CrossLineUsingEncoder_H
#define CrossLineUsingEncoder_H

#include "../CommandBase.h"
#include "WPILib.h"

class CrossLineUsingEncoder : public CommandBase {
public:
	CrossLineUsingEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrossLineUsingEncoder_H
