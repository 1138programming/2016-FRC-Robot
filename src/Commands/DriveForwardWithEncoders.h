#ifndef DriveForwardWithEncoders_H
#define DriveForwardWithEncoders_H

#include "../CommandBase.h"

class DriveForwardWithEncoders : public CommandBase {
public:
	DriveForwardWithEncoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardWithEncoders_H
