#include "ExampleSubsystem.h"

#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

ExampleSubsystem::ExampleSubsystem() :
		frc::Subsystem("ExampleSubsystem") {

}

void ExampleSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SmartDashboard::PutBoolean("Teleop Init", false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

