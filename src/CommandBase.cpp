#include "CommandBase.h"
#include "Commands/Scheduler.h"


// Initialize a single static instance of all of your subsystems to NULL
Collector* CommandBase::collector = NULL;
DriveBase* CommandBase::driveBase = NULL;
Esophagus* CommandBase::esophagus = NULL;
ExampleSubsystem* CommandBase::exampleSubsystem = NULL;
GearCam* CommandBase::gearCam = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
Shooter* CommandBase::shooter = NULL;
ShooterCam* CommandBase::shooterCam = NULL;
OI* CommandBase::oi = NULL;
DriveBase* CommandBase::driveBase = NULL;

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		//std::make_unique<ExampleSubsystem>();
std::unique_ptr<Collector> CommandBase::collector = std::make_unique<Collector>();
std::unique_ptr<DriveBase> CommandBase::driveBase = std::make_unique<DriveBase>();
std::unique_ptr<Esophagus> CommandBase::esophagus = std::make_unique<Esophagus>();
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem = std::make_unique<ExampleSubsystem>();
std::unique_ptr<GearCam> CommandBase::gearCam = std::make_unique<GearCam>();
std::unique_ptr<Pneumatics> CommandBase::pneumatics = std::make_unique<Pneumatics>();
std::unique_ptr<Shooter> CommandBase::shooter = std::make_unique<Shooter>();
std::unique_ptr<ShooterCam> CommandBase::shooterCam = std::make_unique<ShooterCam>();
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	collector = new Collector();
	driveBase = new DriveBase();
	esophagus = new Esophagus();
	exampleSubsystem = new ExampleSubsystem();
	gearCam = new GearCam();
	pneumatics = new Pneumatics();
	shooter = new Shooter();
	shooterCam = new ShooterCam();
	oi = new OI();
}
CommandBase::CommandBase():
		Command()
{

}
