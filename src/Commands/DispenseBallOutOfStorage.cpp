/*
 * DispenseBallOutOfStorage.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: eeuser
 */

#include <Commands/DispenseBallOutOfStorage.h>

DispenseBallOutOfStorage::DispenseBallOutOfStorage()
{
	Requires(CommandBase::collector);
}

void DispenseBallOutOfStorage::Initialize()
{

}

void DispenseBallOutOfStorage::Execute()
{
	CommandBase:collector->DispenseBallOutOfStorage();
}

bool DispenseBallOutOfStorage::IsFinished()
{
	return false;
}

void DispenseBallOutOfStorage::End()
{

}

void DispenseBallOutOfStorage::Interrupted()
{

}
