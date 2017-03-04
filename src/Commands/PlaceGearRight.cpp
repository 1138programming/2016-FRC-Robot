#include "PlaceGearRight.h"
#include "Commands/RightAutonomousTurn1.h"
#include "Commands/RightAutonomousTurn2.h"
#include "Commands/MoveBackwardUsingEncoder1.h"
#include "Commands/MoveBackwardUsingEncoder2.h"
#include "Commands/VisionTracking.h"

PlaceGearRight::PlaceGearRight() {

	//Order of Operations:
	//All of this is backwards because bot is placed backwards on the field (gear collector in back of robot)

	//- Rotate to the left
	//- Move backward
	//- Rotate to the right
	//- Move backward
	//- Vision Tracking


	Requires(CommandBase::driveBase);

	AddSequential(new RightAutonomousTurn1());
	AddSequential(new MoveBackwardUsingEncoder1());
	AddSequential(new RightAutonomousTurn2());
	AddSequential(new MoveBackwardUsingEncoder2());
	AddSequential(new VisionTracking());

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
