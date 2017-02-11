/*
 * EsophagusToBallCollection.h
 *
 *  Created on: Feb 7, 2017
 *      Author: eeuser
 */

#ifndef SRC_COMMANDS_ESOPHAGUSTOBALLCOLLECTION_H_
#define SRC_COMMANDS_ESOPHAGUSTOBALLCOLLECTION_H_

#include "../CommandBase.h"
#include "WPILib.h"

class EsophagusToBallCollection: public CommandBase
{
public:
	EsophagusToBallCollection();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ESOPHAGUSTOBALLCOLLECTION_H_ */
