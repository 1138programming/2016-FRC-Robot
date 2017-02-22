/* SRC_COMMANDS_SHIFTESOPHAGUS_H_ */

#ifndef ShiftEsophagus_H
#define ShiftEsophagus_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftEsophagus: public CommandBase {
public:
	ShiftEsophagus();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif
