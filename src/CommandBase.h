#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>
#include "Subsystems/Collector.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Esophagus.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/GearCam.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/ShooterCam.h"

#include "OI.h"
#include "Subsystems/ExampleSubsystem.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	static std::unique_ptr<OI> oi;

	static Collector* collector;
	static DriveBase* driveBase;
	static Esophagus* esophagus;
	static GearCam* gearCam;
	static Pneumatics* pneumatics;
	static Shooter* shooter;
	static ShooterCam* shooterCam;

};

#endif  // COMMAND_BASE_H
