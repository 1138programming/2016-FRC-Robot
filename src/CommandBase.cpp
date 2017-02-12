#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Commands/Command.h>
#include "Subsystems/Collector.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Esophagus.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/GearCam.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/ShooterCam.h"

#include "Subsystems/ExampleSubsystem.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		std::make_unique<ExampleSubsystem>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

Collector* CommandBase::collector = NULL;
DriveBase* CommandBase::driveBase = NULL;
Esophagus* CommandBase::esophagus = NULL;
GearCam* CommandBase::gearCam = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
Shooter* CommandBase::shooter = NULL;
ShooterCam* CommandBase::shooterCam = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init()
{
	collector = new Collector();
	driveBase = new DriveBase();
	esophagus = new Esophagus();
	gearCam = new GearCam();
	pneumatics = new Pneumatics();
	shooter = new Shooter();
	shooterCam = new ShooterCam();
}
