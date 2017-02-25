#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlywheelsBackward: public CommandBase {
public:
	FlywheelsBackward();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

	float &speed = CommandBase::shooter->flywheelBackwardSpeed;
	// A reference to the flywheelBackwardSpeed variable; Use
	// as a regular variable, and it will update the
	// flywheelBackwardSpeed variable in the shooter
	//
	// See comment in Shooter.h
};

#endif  // EXAMPLE_COMMAND_H
