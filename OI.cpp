
#include "OI.h"
#include "Commands/ShiftBase.h"
#include "Commands/KickBall.h"
#include "Commands/CollectBall.h"
#include "Commands/StopCollect.h"
#include "Commands/FlywheelForward.h"


OI::OI()
{
	//Logitech and xbox controllers.
	//INFO Left Joystick is 0, Right is 1, XBox is 2
	leftController = new Joystick(0);
	rightController = new Joystick(1);
	xBoxController = new Joystick(2);

	//Logitech buttons
	shiftButton = new JoystickButton(leftController, 1);
	reverseDriveButton = new JoystickButton(rightController, 1);

	/****** XBox Button definitions   The ones that are commented out, we aren't using currently ***/
	buttonA	= new JoystickButton(xBoxController, 1);	//Shoot low goal
	buttonB	= new JoystickButton(xBoxController, 2);	//Collect Ball
	buttonX = new JoystickButton(xBoxController, 3);	//Panic Kick
	buttonY = new JoystickButton(xBoxController, 4);	//Shoot High Goal
	//	buttonLB = new JoystickButton(xBoxController, 5);		//left bumper
	//	buttonRB) = new JoystickButton(xBoxController, 6);		//right bumper
	//	buttonSelect = new JoystickButton(xBoxController, 7);	//Select button
	//	buttonStart = new JoystickButton(xBoxController, 8);	//Start button

	shiftButton->WhenPressed(new ShiftBase());
	buttonX->WhenPressed(new KickBall());
	buttonB->WhenPressed(new CollectBall());
	buttonA->WhenPressed(new StopCollect());
	buttonY->WhenPressed(new FlywheelForward);
//	buttonB->WhenReleased(DrivePosition());
}

float OI::getRightController(){			//Right controller is right side drive
	return rightController->GetY();
}

float OI::getLeftController(){			//Left controller is left side drive
	return leftController->GetY();
}

bool OI::getLeftTrigger(){				//left controller's trigger is the shifter
	return shiftButton->Get();
}

bool OI::getRightTrigger(){			//right controller's trigger reverses the base direction
	return reverseDriveButton->Get();
}

float OI::getLeftXBoxAxis(){			//left xbox axis controls the shooter cage pivot
	return -xBoxController->GetRawAxis(1);
}

//controls the collector arms, signal from joystick is reversed
float OI::getRightXBoxAxis(){
	return -xBoxController->GetRawAxis(5);
}

int OI::getXBoxPOV(){					//POV controls the collector arms
	return xBoxController->GetPOV();
}








	/*Project Thunderbolt*/
	/*
	 *
	 * OI::OI()
	 * {
	 * 		//Logitech and xbox controllers
	 * 		leftController = new Joystick(0) ;
	 * 		rightController = new Joystick(1) ;
	 * 		xBoxController = new Joystick(2)
	 *
	 * 		//Logitech Buttons
	 * 		shiftButtonUP = new Joystick(rightController, 1) ;
	 * 		shiftButtonDOWN = new Joystick(leftController, 0) ;
	 *
	 *		//XBox Definitions
	 *		buttonA	= new JoystickButton(xBoxController, 1) ;	//Power Up Shooter -- tap
	 *		buttonB = new JoystickButton(xBoxController, 2) ;	//Turn Off Shooter -- tap
	 *		buttonX = new JoystickButton(xBoxController, 3) ;	//Bag Motor Intake
	 *		buttonY = new JoystickButton(xBoxController, 4) ;	//Bag Motor Outtake
	 *		buttonLB = new JoystickButton(xBoxController, 5) ;	//Lift Initialization
	 *		buttonRB = new JoystickButton(xBoxController, 6) ;	//Esophagus
	 *		//buttonSelect = new JoystickButton(xBoxController, 7) ;
	 *		//buttonStart = new JoystickButton(xBoxController, 8) ;
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 * */

