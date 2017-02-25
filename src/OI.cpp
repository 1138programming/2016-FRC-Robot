#include "OI.h"

#include "Commands/ShiftEsophagus.h"
#include "Commands/VisionTrackingCommand.h"
#include "Commands/ShiftFlywheels.h"
#include "Commands/FlywheelsIncreaseSpeed.h"
#include "Commands/FlywheelsDecreaseSpeed.h"



OI::OI()
{

	//Logitech and xbox controllers
	leftController = new Joystick(0) ;
	rightController = new Joystick(1) ;
	xBoxController = new Joystick(2) ;

	//Logitech Buttons
	shiftButton = new JoystickButton(rightController, 1) ; //Shifts the Base from Low Gear to High Gear and vice versa
	liftButton = new JoystickButton(leftController, 0) ;   //Shifts the Base to Lift the robot and vice versa

	//XBox Definitions
	buttonA	= new JoystickButton(xBoxController, 1) ;	//Toggle Shooter
	buttonB = new JoystickButton(xBoxController, 2) ;	//Toggle Vision
	buttonX = new JoystickButton(xBoxController, 3) ;	//Toggle Esophagus
	buttonLB = new JoystickButton(xBoxController, 5) ;	//Decrease Flywheel Speed
	buttonRB = new JoystickButton(xBoxController, 6) ;	//Increase Flywheel Speed

	shiftButton->WhenPressed(new ShiftBase());
	liftButton->WhenPressed(new ToggleLift());
	buttonX->WhenPressed(new ShiftEsophagus());
	buttonB->WhenPressed(new VisionTrackingCommand());
	buttonA->WhenPressed(new ShiftFlywheels());
	buttonLB->WhenPressed(new FlywheelsDecreaseSpeed());
	buttonRB->WhenPressed(new FlywheelsIncreaseSpeed());

}

float OI::getRightController(){			//Right controller is right side drive
	return rightController->GetY();
}

float OI::getLeftController(){			//Left controller is left side drive
	return leftController->GetY();
}

bool OI::getLeftTrigger(){				//left controller's trigger is the shifter
	return liftButton->Get();
}

bool OI::getRightTrigger(){			//right controller's trigger reverses the base direction
	return shiftButton->Get();
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
