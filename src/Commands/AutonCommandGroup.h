#ifndef AutonCommandGroup_H
#define AutonCommandGroup_H
#include <WPILib.h>
#include <Commands/CommandGroup.h>

class AutonCommandGroup : public CommandGroup {
public:
	AutonCommandGroup(float distancetobaseline,
					float turntopilottowerdegrees,
					float distancetopilottower,
					float autonstraightspeed,
					float autonturnspeed,
					bool turningleft);
};

#endif  // AutonCommandGroup_H
