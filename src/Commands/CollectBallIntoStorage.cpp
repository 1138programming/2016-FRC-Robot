/*
 * CollectBallIntoStorage.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: eeuser
 */

#include <Commands/CollectBallIntoStorage.h>

CollectBallIntoStorage::CollectBallIntoStorage()
{
	Requires(CommandBase::collector);
}

void CollectBallIntoStorage::Initialize()
{

}

void CollectBallIntoStorage::Execute()
{
	CommandBase:collector->CollectBallIntoStorage();
}

bool CollectBallIntoStorage::IsFinished()
{
	return false;
}

void CollectBallIntoStorage::End()
{

}

void CollectBallIntoStorage::Interrupted()
{

}
