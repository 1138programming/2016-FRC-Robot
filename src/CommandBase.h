#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "Subsystems/DriveBase.h"

#include "OI.h"
#include "WPILib.h"

#include "C:\Users\eeuser\wpilib\user\cpp\include\CANTalon.h"
//#include "Subsystems/ExampleSubsystem.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command
{
public:
	CommandBase(const std::string& name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	/*static std::uniqueptr<ExampleSubsystem> exampleSubsystem;
	static std::unique_ptr<OI> oi;*/
	static DriveBase* driveBase;
	static OI* oi;
};

#endif  // COMMAND_BASE_H
