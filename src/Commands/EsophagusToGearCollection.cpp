/*
 * EsophagusToGearCollection.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: eeuser
 */

#include <Commands/EsophagusToGearCollection.h>

EsophagusToGearCollection::EsophagusToGearCollection()
{
	Requires(CommandBase::esophagus);
}

void EsophagusToGearCollection::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EsophagusToGearCollection::Execute()
{
	CommandBase::esophagus->MoveEsophagusToGearCollection();
}

// Make this return true when this Command no longer needs to run execute()
bool EsophagusToGearCollection::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void EsophagusToGearCollection::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EsophagusToGearCollection::Interrupted()
{

}
