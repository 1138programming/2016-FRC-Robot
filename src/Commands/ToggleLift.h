#ifndef ToggleLift_H
#define ToggleLift_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\WPILib.h"
#include "C:\Users\eeuser\wpilib\cpp\current\include\Solenoid.h"

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
