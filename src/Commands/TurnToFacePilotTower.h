#ifndef TurnToFacePilotTower_H
#define TurnToFacePilotTower_H

#include "../CommandBase.h"

class TurnToFacePilotTower : public CommandBase {
public:
	TurnToFacePilotTower(float autonturndegrees, float autonturnspeed, bool autonleftturn);
	void Initialize();
	void Execute(float autonturndegrees, float autonturnspeed, bool autonleftturn);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurnToFacePilotTower_H
