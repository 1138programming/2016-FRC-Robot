#include "CommandBase.h"

#include <Commands/Scheduler.h>


#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Pneumatics.h"


// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		//std::make_unique<ExampleSubsystem>();
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;




std::unique_ptr<Pneumatics> CommandBase::pneumatics = std::make_unique<Pneumatics>();


CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
CommandBase::CommandBase():
		Command()
{

}

void CommandBase::init()
{
	driveBase = new DriveBase();
	oi = new OI();
}
