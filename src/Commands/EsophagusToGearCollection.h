/*
 * EsophagusToGearCollection.h
 *
 *  Created on: Feb 7, 2017
 *      Author: eeuser
 */

#ifndef SRC_COMMANDS_ESOPHAGUSTOGEARCOLLECTION_H_
#define SRC_COMMANDS_ESOPHAGUSTOGEARCOLLECTION_H_

#include "../CommandBase.h"
#include "WPILib.h"

class EsophagusToGearCollection: public CommandBase
{
public:
	EsophagusToGearCollection();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ESOPHAGUSTOGEARCOLLECTION_H_ */
