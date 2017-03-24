#ifndef OpenEsophagus_H
#define OpenEsophagus_H

#include "../CommandBase.h"

class OpenEsophagus : public CommandBase {
public:
	OpenEsophagus();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenEsophagus_H
