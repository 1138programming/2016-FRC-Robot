#ifndef OI_H
#define OI_H

#include "WPILib.h"


class OI
{

private:
		//Three joysticks -- 2 logitech; 1 xbox
		Joystick* leftController ;	//Left Drive Base
		Joystick* rightController ;	//Right Drive Base
		Joystick* xBoxController ;	//Runs Collector

public:
		//Logitech Button Definitions
		JoystickButton* shiftButton ; //Right Trigger
		JoystickButton* liftButton ; //Left Trigger

		//XBox Button Definitions
		JoystickButton* buttonA ;		//Toggle Shooter System
		JoystickButton* buttonB ;		//Toggle Vision Tracking
		JoystickButton* buttonX ;		//Toggle Esophagus
		JoystickButton* buttonLB ;		//Decrease Flywheel Speed
		JoystickButton* buttonRB ;		//Increase Flywheel Speed
		//JoystickButton* buttonSelect ;
		//JoystickButton* buttonStart ;

	OI();
	float getRightController() ;		//Right Controller is the Right Side Drive
	float getLeftController() ;			//Left Controller is the Left Side Drive
	bool getLeftTrigger() ;
	bool getRightTrigger() ;
	float getLeftXBoxAxis() ;			//Controls collector roller
	float getRightXBoxAxis() ;			//Collector roller granny gear
//	int getXBoxPOV() ;					//No function

} ;


#endif
