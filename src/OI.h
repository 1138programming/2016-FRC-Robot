#ifndef OI_H
#define OI_H

#include "WPILib.h"


class OI
{
private:
		/*Three joysticks - 2 logitech and one xbox.   */
		Joystick* leftController;	//left drive base
		Joystick* rightController;	//right drive base
		Joystick* xBoxController;	//arms and lifts

public:
		/******* Logitech Button definitions */
		JoystickButton* shiftButton;
		JoystickButton* reverseDriveButton;

		/****** XBox Button definitions   The ones that are commented out, we aren't using currently ***/
		JoystickButton* buttonA;		//Shoot Low Goal
		JoystickButton* buttonB;		//Collect Ball
		JoystickButton* buttonX;		//Panic Kick
		JoystickButton* buttonY;		//Shoot High Goal
		//	JoystickButton* buttonLB;		//left bumper
		//	JoystickButton* buttonRB);		//right bumper
		//	JoystickButton* buttonSelect;	//Select button
		//	JoystickButton* buttonStart;	//Start button





		/*Project Thunderbolt*/
		/*
		 * #include "WPILib.h"
		 *
		 *
		 *class OI
		 *{
		 * 	private:
		 * 		//Three joysticks -- 2 logitech; 1 xbox
		 * 		Joystick* leftController ;	//Left Drive Base
		 * 		Joystick* rightController ;	//Right Drive Base
		 * 		Joystick* xBoxController ;	//Arms and Lifts
		 *
		 * 	public:
		 * 		//Logitech Button Definitions
		 * 		JoystickButton* shiftButtonUP ; //Right Trigger
		 * 		JoystickButton* shiftButtonDOWN ; //Left Trigger
		 *
		 * 		//XBox Button Definitions
		 * 		JoystickButton* buttonA ;		//Power Up Shooter -- *tap*
		 * 		JoystickButton* buttonB ;		//Turn Off Shooter -- *tap*
		 * 		JoystickButton* buttonX ;		//Bag Motor intake -- to the shooter
		 * 		JoystickButton* buttonY ;		//Bag Motor outtake -- out of holder
		 * 		JoystickButton* buttonLB ;		//Lift Initialization
		 * 		JoystickButton* buttonRB ;		//Esophagus Control
		 * 		//JoystickButton* buttonSelect ;
		 * 		//JoystickButton* buttonStart ;
		 *
		 *
		 *
		 *	OI();
		 *	float getRightController() ;		//Right Controller is the Right Side Drive
		 *	float getLeftController() ;			//Left Controller is the Left Side Drive
		 *	//bool getLeftTrigger() ;
		 *	//bool getRightTrigger() ;
		 *	float getLeftXBoxAxis() ;			//Controls collector roller - up = intake; down = outtake
		 *	float getRightXBoxAxis() ;			//No function
		 *	int getXBoxPOV() ;					//No function
		 *
		 *} ;
		 *
		 *
		 *
		 *#endif
		 *
		 */
		/*Project Thunderbolt*/

	OI();
	/***********************************************************
	 * Define methods for the joysticks
	 */
	float getRightController();			//Right controller is right side drive
	float getLeftController();			//Left controller is left side drive
	bool getLeftTrigger();				//left controller's trigger is the shifter
	bool getRightTrigger();			//right controller's trigger reverses the base direction
	float getLeftXBoxAxis();			//left xbox axis controls the shooter cage pivot
	float getRightXBoxAxis();			//no function for this currently
	int getXBoxPOV();					//POV controls the collector arms

};

#endif
