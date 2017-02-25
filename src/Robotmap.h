/*
 * Robotmap.h
 *
 *  Created on: Feb 25, 2017
 *      Author: eeuser
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"
#include "c:\Users\eeuser\wpilib\cpp\current\include\Ultrasonic.h"
//#include "C:\Users\eeuser\wpilib\cpp\current\include\SmartDashboard\SmartDashboard.h"

class Robotmap {

private:

		//Subsystem Talons and Solenoids
		//Collector
		CANTalon* collectorCIM;

		//Drive Base Talons and Solenoids
		CANTalon* LeftRearBaseMotor; //Talon 1 in CAN Bus
		CANTalon* LeftFrontBaseMotor; //Talon 2 in CAN Bus
		CANTalon* RightRearBaseMotor; //Talon 3 in CAN Bus
		CANTalon* RightFrontBaseMotor; //Talon 4 in CAN Bus

		//Flywheel Talons
		CANTalon* flywheelRight;
		CANTalon* flywheelLeft;
		CANTalon* filterFront;
		CANTalon* filterRear;

		//Solenoids
		//Drive Base Solenoids
		DoubleSolenoid* shiftSolenoid;
		DoubleSolenoid* liftSolenoid;

		//Esophagus Solenoid
		DoubleSolenoid* esophagusSolenoid;

		//Joysticks
		Joystick* l_stick; //Logitech Joystick
		Joystick* r_stick; //Logitech Joystick
		Joystick* x_stick; //X-Box Joystick

		//Sensors
		//NavX MXP
		AHRS* ahrs;

			//Ultrasonic
		Ultrasonic* BaseUltrasonic;

		PowerDistributionPanel* myPDP;
		//Live Window
		//LiveWindow* lw = LiveWindow::GetInstance();

		//USB Camera
		static CameraServer* GetInstance();

		//update every 0.005 seconds/5 milliseconds.
		double kUpdatePeriod = 0.005;

		const float KRamp = 0.6;

public:
		Robotmap();

	//Talons
	const int RightFrontBaseTalon = 1;
	const int RightRearBaseTalon = 3;
	const int LeftFrontBaseTalon = 2;
	const int LeftRearBaseTalon = 4;
	const int flywheelLeftTalon = 8;
	const int flywheelRightTalon = 7;
	const int filterFrontTalon = 5;
	const int filterRearTalon = 6;
	const int CollectorTalon = 9;

	//Solenoids
	const int shiftSolenoidForward = 0;
	const int shiftSolenoidReverse = 1;
	const int liftSolenoidForward = 2;
	const int liftSolenoidReverse = 3;
	const int esophagusSolenoidForward = 4;
	const int esophagusSolenoidReverse = 5;

	//Joysticks
	const int JoystickPort1 = 1;
	const int JoystickPort0 = 0;
	const int JoystickPort2 = 2;

	//Ultrasonic
	const int BaseUltrasonicTransmitter = 1;
	const int BaseUltrasonicReciever = 1;

	//Gyro
	const float ahrsPort = SPI::Port::kMXP;

	//PDP
	const int PDPPort = 0;
};


#endif /* SRC_ROBOTMAP_H_ */
