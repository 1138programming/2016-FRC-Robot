#include "OI.h"

#include "Commands/ToggleEsophagus.h"
#include "Commands/VisionTracking.h"
#include "Commands/ToggleLift.h"
#include "Commands/ShiftBase.h"
#include "Commands/EngageShooter.h"
#include "Commands/FlywheelIncreaseSpeed.h"
#include "Commands/FlywheelDecreaseSpeed.h"



OI::OI()
{

	//Logitech and xbox controllers
	leftController = new Joystick(0) ;
	rightController = new Joystick(1) ;
	xBoxController = new Joystick(2) ;

	//Logitech Buttons
	shiftButton = new JoystickButton(rightController, 1) ; //Shifts the Base from Low Gear to High Gear and vice versa
	liftButton = new JoystickButton(leftController, 1) ;   //Shifts the Base to Lift the robot and vice versa

	//XBox Definitions
	buttonA	= new JoystickButton(xBoxController, 1) ;	//Toggle Shooter
	buttonB = new JoystickButton(xBoxController, 2) ;	//Toggle Vision
	buttonX = new JoystickButton(xBoxController, 3) ;	//Toggle Esophagus
	buttonLB = new JoystickButton(xBoxController, 5) ;	//Decrease Flywheel Speed
	buttonRB = new JoystickButton(xBoxController, 6) ;	//Increase Flywheel Speed

	shiftButton->WhenPressed(new ShiftBase());
	liftButton->WhenPressed(new ToggleLift());
	buttonX->WhenPressed(new ToggleEsophagus());
	buttonB->WhenPressed(new VisionTracking());
	buttonA->WhenPressed(new EngageShooter());
	buttonLB->WhenPressed(new FlywheelDecreaseSpeed());
	buttonRB->WhenPressed(new FlywheelIncreaseSpeed());

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

bool OI::getRightTrigger(){			//right controller's trigger engages the lift
	return shiftButton->Get();
}

float OI::getLeftXBoxAxis(){			//left xbox axis controls the collector
	return -xBoxController->GetRawAxis(1);
}

//Fine control from collector, signal from joystick is reversed
float OI::getRightXBoxAxis(){
	return -xBoxController->GetRawAxis(5);
}
//
//int OI::getXBoxPOV(){					//POV controls the collector arms
//	return xBoxController->GetPOV();
//
//}


