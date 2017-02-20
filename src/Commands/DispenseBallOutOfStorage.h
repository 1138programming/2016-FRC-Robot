#ifndef SRC_COMMANDS_DISPENSEBALLOUTOFSTORAGE_H_
#define SRC_COMMANDS_DISPENSEBALLOUTOFSTORAGE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class DispenseBallOutOfStorage: public CommandBase
{
public:
	DispenseBallOutOfStorage();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_DISPENSEBALLOUTOFSTORAGE_H_ */
