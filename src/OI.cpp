#include "OI.h"

#include "Commands/ToggleEsophagus.h"
#include "Commands/CloseEsophagus.h"
#include "Commands/OpenEsophagus.h"
#include "Commands/VisionTracking.h"
#include "Commands/ToggleLift.h"
#include "Commands/ShiftBase.h"
#include "Commands/EngageShooter.h"
#include "Commands/FlywheelIncreaseSpeed.h"
#include "Commands/FlywheelDecreaseSpeed.h"
#include "Commands/DisengageShooter.h"
#include "RobotMap.h"



OI::OI()
{

	//Logitech and xbox controllers
	leftController = new Joystick(KLeftJoystick) ;
	rightController = new Joystick(KRightJoystick) ;
	xBoxController = new Joystick(KXBoxController) ;

	//Logitech Buttons
	shiftButton = new JoystickButton(rightController, 1) ; //Shifts the Base from Low Gear to High Gear and vice versa
	liftButton = new JoystickButton(leftController, 7) ;   //Shifts the Base to Lift the robot and vice versa

	//XBox Definitions
	buttonA	= new JoystickButton(xBoxController, KButtonA) ;	//Toggle Vision
	buttonB = new JoystickButton(xBoxController, KButtonB) ;	//Toggle Esophagus
	buttonX = new JoystickButton(xBoxController, KButtonX) ;	//Turn on shooter
	buttonY = new JoystickButton(xBoxController, KButtonY) ;	//Turn off shooter
	buttonLB = new JoystickButton(xBoxController, KLeftBumper) ;	//Decrease Flywheel Speed
	buttonRB = new JoystickButton(xBoxController, KRightBumpter) ;	//Increase Flywheel Speed

	shiftButton->WhenPressed(new ShiftBase());
	liftButton->WhenPressed(new ToggleLift());
	buttonX->WhenPressed(new EngageShooter());
	buttonY->WhenPressed(new DisengageShooter());
	buttonB->WhenPressed(new ToggleEsophagus());
	buttonA->WhenPressed(new VisionTracking());
	buttonLB->WhenPressed(new OpenEsophagus());		//buttonLB->WhenPressed(new FlywheelDecreaseSpeed());
	buttonRB->WhenPressed(new CloseEsophagus());	//buttonRB->WhenPressed(new FlywheelIncreaseSpeed());

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


