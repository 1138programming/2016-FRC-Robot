#ifndef EngageLift_H
#define EngageLift_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\WPILib.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\Solenoid.h"

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
