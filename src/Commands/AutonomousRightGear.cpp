#include "AutonomousRightGear.h"
#include "Subsystems/DriveBase.h"
#include "Commands/MoveBackwardWithEncoders.h"
#include "Commands/TurnToFacePilotTower.h"


AutonomousRightGear::AutonomousRightGear()
{
//	Requires(CommandBase::driveBase);


	AddSequential(new MoveBackwardWithEncoders(KRevsToBaseLine, KAutonStraightSpeed));
	SmartDashboard::PutBoolean("About to do the turn", true);
	AddSequential(new TurnToFacePilotTower(KTurnToPilotTower, KAutonTurnSpeed, KLeftTurn));
	SmartDashboard::PutBoolean("About to do the second move", true);
	AddSequential(new MoveBackwardWithEncoders(KRevsToPilotTower, KAutonStraightSpeed));
}
