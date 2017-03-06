#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;
/*Talons:
1 - Front Base Right
2 - Front Base Left
3 - Rear Base Right
4 - Rear Base Left
5 - Flywheel Right
6 - Flywheel Left
7 - Filter Right
8 - Filter Left
9 - Collector
10 - Spare
Solenoids:
0 and 1 - Base Solenoid (shift)
2 and 3 - Collector/Ratchet Solenoid
4 and 5 - Esophagus*/

const float KLeftRearBaseTalon =  4;
const float KLeftFrontBaseTalon = 2 ;
const float KRightRearBaseTalon = 3 ;
const float KRightFrontBaseTalon = 1 ;
const float KFlywheelRightTalon = 5;
const float KFlywheelLeftTalon = 6;
const float KFilterFrontTalon = 7;
const float KFilterRearTalon = 8;
const float KCollectorTalon = 9;

const float KLeftBaseMaster = 1; //KLeftMaster = Master Talon for left side
const float KRightBaseMaster = 2; //KRightMaster = Master Talon for right side

//all of the solenoids are doubles, so they need 2 numbers each.  If you change one, be sure to change
//the other one of the pair.
const float KShifterSolenoid1 = 0;		//TODO swapped shifter and lift solenoids for testing.
const float KShifterSolenoid2 = 1;		//must be changed back
const float KLiftSolenoid1 = 2;
const float KLiftSolenoid2 = 3;
const float KEsophagusSolenoid1 = 4;
const float KEsophagusSolenoid2 = 5;

//Sensors
const float KBaseUltrasonic1 = 0;
const float KBaseUltrasonic2 = 1;


#endif  // ROBOTMAP_H
