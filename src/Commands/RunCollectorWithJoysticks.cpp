#include "RunCollectorWithJoysticks.h"

RunCollectorWithJoysticks::RunCollectorWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::collector);
}

// Called just before this Command runs the first time
void RunCollectorWithJoysticks::Initialize() {
//	SmartDashboard::PutBoolean("Collector Init", false);
}

// Called repeatedly when this Command is scheduled to run
void RunCollectorWithJoysticks::Execute()
{
/**
 * When the shooter is not engaged, the collector runs off the xbox joysticks
 * The left axis runs the collector fast when it is pressed forward or backwards
 * The right axis runs the collector slowly when it is pressed forward or bachwards
 * The left joystick overrides the right joystick
 * If the shooter is engaged, the joysticks are disabled
 */
//	if(shooter->QueryShooterState() == false)
//	{
		float collectorSpeedFAST;
		float collectorSpeedSLOW;

		collectorSpeedFAST = CommandBase::oi->getLeftXBoxAxis();	//fast speed if the left joystick is pushed

		SmartDashboard::PutNumber("LeftXboxJoystick", CommandBase::oi->getLeftXBoxAxis());

		collectorSpeedSLOW = CommandBase::oi->getRightXBoxAxis();

		SmartDashboard::PutNumber("RightXBoxJoystick", CommandBase::oi->getRightXBoxAxis());
		//Left joystick overrides the right one, so if we want to go fast that is what we do.
		if(collectorSpeedFAST > KXboxDeadZoneLimit || collectorSpeedFAST < -KXboxDeadZoneLimit)
		{
			CommandBase::collector->RunCollector(-collectorSpeedFAST);
		}
		//if the left joystick isn't pushed, check to see if we want to try and catch the knot for lift
		//by pressing the right joystick
		else
		{
			if(collectorSpeedSLOW > KXboxDeadZoneLimit)
			{
				CommandBase::collector->RunCollector(KcollectorSpeedSLOW);	//run very slow to catch the knot
			}
			else
			{
				if ( collectorSpeedSLOW < -KXboxDeadZoneLimit)
				{
					CommandBase::collector->RunCollector(-KcollectorSpeedSLOW);	//run very slow to catch the knot
				}
				else		//neither joystick is pressed, so just stop the collector motors.
				{
					CommandBase::collector->StopCollector();
				}
			}
		}
	}		//if the shooter state is true, the collector runs as part of the shooter, and the collector joysticks are ignored.
//}

// Make this return true when this Command no longer needs to run execute()
bool RunCollectorWithJoysticks::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunCollectorWithJoysticks::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunCollectorWithJoysticks::Interrupted() {

}
