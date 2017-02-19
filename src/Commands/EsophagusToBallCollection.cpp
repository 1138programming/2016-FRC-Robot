/*
 * EsophagusToBallCollection.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: eeuser
 */

#include <Commands/EsophagusToBallCollection.h>

EsophagusToBallCollection::EsophagusToBallCollection()
{
	Requires(CommandBase::esophagus);
}

void EsophagusToBallCollection::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EsophagusToBallCollection::Execute()
{
	CommandBase::esophagus->MoveEsophagusToBallCollection();
}

// Make this return true when this Command no longer needs to run execute()
bool EsophagusToBallCollection::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EsophagusToBallCollection::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EsophagusToBallCollection::Interrupted()
{

}
