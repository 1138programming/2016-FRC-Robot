#include "AutonomousLeftGear.h"
#include "Subsystems/DriveBase.h"
#include "Commands/MoveBackwardWithEncoders.h"
#include "Commands/TurnToFacePilotTower.h"

AutonomousLeftGear::AutonomousLeftGear()
{
	Requires(CommandBase::driveBase);
	SmartDashboard::PutBoolean("Doing Left Gear Auton", true);
	AddSequential(new MoveBackwardWithEncoders(KRevsToBaseLine, KAutonStraightSpeed));

	AddSequential(new TurnToFacePilotTower(KTurnToPilotTower, KAutonTurnSpeed, KRightTurn));

	AddSequential(new MoveBackwardWithEncoders(KRevsToPilotTower, KAutonStraightSpeed));
}
