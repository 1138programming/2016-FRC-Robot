#ifndef SRC_COMMANDS_COLLECTBALLINTOSTORAGE_H_
#define SRC_COMMANDS_COLLECTBALLINTOSTORAGE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class CollectBallIntoStorage: public CommandBase
{
public:
	CollectBallIntoStorage();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_COLLECTBALLINTOSTORAGE_H_ */
