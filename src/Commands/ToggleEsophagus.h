#ifndef ToggleEsophagus_H
#define ToggleEsophagus_H

#include "../CommandBase.h"
#include "../Subsystems/Esophagus.h"

class ToggleEsophagus : public CommandBase {
public:
	ToggleEsophagus();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleEsophagus_H
