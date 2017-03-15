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
const float KShifterSolenoid1 = 0;
const float KShifterSolenoid2 = 1;
const float KLiftSolenoid1 = 2;
const float KLiftSolenoid2 = 3;
const float KEsophagusSolenoid1 = 4;
const float KEsophagusSolenoid2 = 5;

//Sensors
const float KBaseUltrasonic1 = 0;
const float KBaseUltrasonic2 = 1;

const float KDeadZoneLimit = 0.1;


//Circumerence of wheel - 330.2 millimeters. Divide by this number to get number of rotations for distances
const float KDistanceToBaseLine = 6.98;	//rotations from the diamond plate to the baseline from Field CAD
const float KDistanceToPilotTower = 6.099; //rotations from the baseline to the pilot tower from Field CAD
const float KTurnToPilotTower = 40.1;	//degrees to turn from the baseline to face the pilot tower.  Add direction using sign.
const float KAutonStraightSpeed = -.3;	//TODO lets go slowly and backwards
const float KAutonTurnSpeed = .2; //TODO turn slowly towards pilot tower
const float KCrossTheLineDistance = 2500; //Unofficial distance to cross the line in autonomous
const float KVisionTrackingDistance = 2000; //Unofficial distance (in mm) until we turn on vision tracking

const bool KLeftTurn = true;
const bool KRightTurn = false;

#endif  // ROBOTMAP_H
