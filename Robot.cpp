#include <iostream>
#include <memory>
#include <string>

#include <Joystick.h>
#include "CANTalon.h"
#include "AHRS.h"
#include <SmartDashboard/SmartDashboard.h>




	class Robot : public SampleRobot
{
	// The motor to control with the Joystick.
	// This uses a Talon speed controller; use the Victor or Jaguar classes for
	//   other speed controllers.
	CANTalon* motor_rear_left;
	CANTalon* motor_front_left;
	CANTalon* motor_rear_right;
	CANTalon* motor_front_right;
	Joystick* l_stick; //Logitech Joystick
	Joystick* r_stick; //XBox Joystick
	AHRS *ahrs;
	LiveWindow *lw = LiveWindow::GetInstance();


	//update every 0.005 seconds/5 milliseconds.
	double kUpdatePeriod = 0.005;

public:

	/**
	 * Runs the motor from the output of a Joystick.
	 */
	void OperatorControl() {
		l_stick = new Joystick(1); // Initialize Joystick on port 1.
		r_stick = new Joystick(2); // Initialize Joystick on port 2.

//		ahrs = new AHRS(SPI::Port::kMXP);
		//ahrs->ZeroYaw();
		lw->AddSensor("Robot", "9AxisGyro", ahrs);
/*
		This is a temporary definition to test the practice bot.  doesn't agree with
		competition bot.
		10 front base right- master, encoder
		1  front base left - master, encoder
		3 rear base right
		4 rear base left
*/

		//Left side motors
		motor_rear_left = new CANTalon(4);
		motor_front_left = new CANTalon(1);
		motor_front_left->SetInverted(true);
		//The rear motor is following the front motor
		motor_rear_left->SetControlMode(CANTalon::kFollower);
		motor_rear_left->Set(1);

		//Right side motors, these are running inverted.
		motor_rear_right = new CANTalon(3);
		motor_front_right = new CANTalon(10);
		//The rear motor is following the front motor
		motor_rear_right->SetControlMode(CANTalon::kFollower);
		motor_rear_right->Set(10);

		//12bit encoder, 4096 ticks per rotation
//		motor_front_left->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
//		motor_front_left->SetSensorDirection(false); /* keep sensor and motor in phase */
//		motor_front_right->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
//		motor_front_right->SetSensorDirection(true); /* keep sensor and motor in phase */

		while (IsOperatorControl() && IsEnabled())
		{
			// Set the motor controller's output.
			// This takes a number from -1 (100% speed in reverse) to +1 (100% speed forwards).
			motor_front_left->Set(l_stick->GetY());
			motor_front_right->Set(r_stick->GetY());
			lw->Run();

//			if(ahrs->GetYaw() < 15 && ahrs->GetYaw() > -15)
//				motor_rear_right->Set(0.2);
//			else
//				motor_rear_right->Set(0);
			Wait(kUpdatePeriod); // Wait 5ms for the next update.
		}
	}
};

START_ROBOT_CLASS(Robot)
