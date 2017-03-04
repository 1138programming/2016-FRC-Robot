#ifndef MoveBackwardUsingEncoderCentral_H
#define MoveBackwardUsingEncoderCentral_H

#include "../CommandBase.h"

class MoveBackwardUsingEncoderCentral : public CommandBase {
public:
	MoveBackwardUsingEncoderCentral();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBackwardUsingEncoderCentral_H
