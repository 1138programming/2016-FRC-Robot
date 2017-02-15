#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DriveBase.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		//std::make_unique<ExampleSubsystem>();
DriveBase* CommandBase::driveBase = NULL;

//std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
CommandBase::CommandBase()
{

}
static void CommandBase::init()
{
	driveBase = new DriveBase();
}
