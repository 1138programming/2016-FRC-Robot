#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include "Commands/Command.h"
#include "Subsystems/Collector.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Esophagus.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/GearCam.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/ShooterCam.h"
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

	CommandBase() = default;

	static void init();

	// Create a single static instance of all of your subsystems
// 	static Collector* collector;
// 	static DriveBase* driveBase;
// 	static Esophagus* esophagus;
// 	static ExampleSubsystem* exampleSubsystem;
// 	static GearCam* gearCam;
// 	static Pneumatics* pneumatics;
// 	static Shooter* shooter;
// 	static ShooterCam* shooterCam;
// 	static OI* oi;

// Create a single static instance of all of your subsystems

	static std::unique_ptr<Collector> collector;
  static std::unique_ptr<DriveBase> driveBase;
	static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	static std::unique_ptr<Esophagus> esophagus;
		static std::unique_ptr<GearCam> gearCam;
    	static std::unique_ptr<Shooter> shooter;
      	static std::unique_ptr<ShooterCam> shooterCam;
        	static std::unique_ptr<OI> oi;
  static std::unique_ptr<Pneumatics> pneumatics;


};

#endif  // COMMAND_BASE_H
