#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/Shooter.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		std::make_unique<ExampleSubsystem>();


std::unique_ptr<Pneumatics> CommandBase::pneumatics = std::make_unique<Pneumatics>();
std::unique_ptr<Shooter> CommandBase::shooter = std::make_unique<Shooter>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
