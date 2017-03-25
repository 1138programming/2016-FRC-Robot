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
const float KXboxDeadZoneLimit = 0.2;

//Constants for Autonomous routines
//Circumference of wheel - 330.2 millimeters. Divide by this number to get number of rotations for distances
const float KWheelRadius = 5.255; //In centimeters
const float KWheelCircumference = 33.02; //In centimeters
const float KDistanceToBaseLine = 191.64; //In centimeters
const float KDistanceToPilotTower = 86.86; //In centimeters
const float KRevsToBaseLine = KDistanceToBaseLine / KWheelCircumference;	//rotations from the diamond plate to the baseline from Field CAD (191.64cm)
const float KRevsToPilotTower = KDistanceToPilotTower / KWheelCircumference; //rotations from the baseline to the pilot tower from Field CAD (86.86cm)
const float KTurnToPilotTower = 55;	//degrees to turn from the baseline to face the pilot tower.
const float KAutonStraightSpeed = .5;	//TODO lets go slowly and backwards
const float KAutonTurnSpeed = .5; //TODO turn slowly towards pilot tower
const float KRevsToCrossTheLine = 10; //Unofficial distance to cross the line in autonomous
const float KRevsToVisionTracking = 3; //Unofficial distance  until we turn on vision tracking
const float KEncoderTicksPerRev = 4096; //The amount of ticks it takes to do one full rotation with the encoder

//Okay, don't get clever and decide this isn't actually the way we are turning.  I don't care which way we are turning.
//Left turn means the turn we make when our starting position is on the left side of the field.  Right Turn is when
//our starting position is on the right side of the field.  We are also doing the turn going backwards and that
//changes the direction too.  Don't think to much about this or your brain will explode.
const bool KLeftTurn = true;
const bool KRightTurn = false;

//Joystick Definitions
const int KLeftJoystick = 0 ;
const int KRightJoystick = 1 ;
const int KXBoxController = 2;

//XBox button definitions
const int KButtonA = 1 ;	//Toggle Vision
const int KButtonB = 2 ;	//Toggle Esophagus
const int KButtonX = 3 ;	//Turn on shooter
const int KButtonY = 4 ;	//Turn off shooter
const int KLeftBumper = 5 ;	//Decrease Flywheel Speed
const int KRightBumpter = 6 ;


#endif  // ROBOTMAP_H
