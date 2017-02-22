/*
 * ShiftEsophagus.cpp
 *
 *  Created on: Feb 21, 2017
 *      Author: eeuser
 */

#include <Commands/ShiftEsophagus.h>

ShiftEsophagus::ShiftEsophagus() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::esophagus);
}

// Called just before this Command runs the first time
void ShiftEsophagus::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShiftEsophagus::Execute()
{
	CommandBase::esophagus->ShiftGearBallCollection();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftEsophagus::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftEsophagus::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftEsophagus::Interrupted() {

}
