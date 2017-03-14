#include "CommandBase.h"
#include "Commands/Scheduler.h"


// Initialize a single static instance of all of your subsystems to NULL
//Collector* CommandBase::collector = NULL;
DriveBase* CommandBase::driveBase = NULL;
Collector* CommandBase::collector = NULL;
Esophagus* CommandBase::esophagus = NULL;
//ExampleSubsystem* CommandBase::exampleSubsystem = NULL;
GearCam* CommandBase::gearcam = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
Shooter* CommandBase::shooter = NULL;
ShooterCam* CommandBase::shooterCam = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//collector = new Collector();
	driveBase = new DriveBase();
	esophagus = new Esophagus();
	collector = new Collector();
//	exampleSubsystem = new ExampleSubsystem();
	gearcam = new GearCam();
	pneumatics = new Pneumatics();
	shooter = new Shooter();
	shooterCam = new ShooterCam();
	oi = new OI();

}
CommandBase::CommandBase():
		Command()
{

}
