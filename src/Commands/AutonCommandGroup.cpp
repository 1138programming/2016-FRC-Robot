#include "AutonCommandGroup.h"
#include "Commands/MoveBackwardWithEncoders.h"
#include "Commands/TurnToFacePilotTower.h"
#include "Commands/EngageShooter.h"

AutonCommandGroup::AutonCommandGroup(float distancetobaseline,
									 float turntopilottowerdegrees,
									 float distancetopilottower,
									 float autonstraightspeed,
									 float autonturnspeed,
									 bool turningleft)
{
	Requires(CommandBase::driveBase);
	AddSequential(new MoveBackwardWithEncoders(distancetobaseline,
											   autonstraightspeed));
	AddSequential(new TurnToFacePilotTower(turntopilottowerdegrees,
										   autonturnspeed,
										   turningleft));
	AddSequential(new MoveBackwardWithEncoders(distancetopilottower,
											   autonstraightspeed));
}
