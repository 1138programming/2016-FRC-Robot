#ifndef VisionCommand_H
#define VisionCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class VisionTracking : public CommandBase {
public:
	VisionTracking();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // VisionCommand_H
