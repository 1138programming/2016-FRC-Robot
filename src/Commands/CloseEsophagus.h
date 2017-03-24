#ifndef CloseEsophagus_H
#define CloseEsophagus_H

#include "../CommandBase.h"

class CloseEsophagus : public CommandBase {
public:
	CloseEsophagus();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CloseEsophagus_H
