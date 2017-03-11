#ifndef MoveBackwardWithEncoders_H
#define MoveBackwardWithEncoders_H

#include "../CommandBase.h"

class MoveBackwardWithEncoders : public CommandBase {
public:
	MoveBackwardWithEncoders(float autondistance, float autonbasespeed);
	void Initialize();
	void Execute(float autondistance, float autonbasespeed);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBackwardWithEncoders_H
