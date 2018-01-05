#ifndef SRC_UTILITIES_GLOBALDEFINES_H_
#define SRC_UTILITIES_GLOBALDEFINES_H_

//#define TUNING_PIDS

//Drive Config
#define DRIVE_X_AXIS 0
#define DRIVE_Y_AXIS 1
#define DRIVE_SHIFT_HOLDLOW 8
#define DRIVE_SHIFT_LOW 7
#define DRIVE_SHIFT_HIGH 6

//Gear Subsystem Buttons
#define GEAR_SUBSYSTEM_ACTUATE_DOWN 1
#define GEAR_SUBSYSTEM_ACTUATE_UP 2
#define GEAR_SUBSYSTEM_CLOSE_CLAMP 3
#define GEAR_SUBSYSTEM_OPEN_CLAMP 4
#define PICKUP_GEAR 5
#define PLACE_GEAR 6
#define DRIVER_PICKUP_GEAR 10
#define DRIVER_PLACE_GEAR 11

//Intake Buttons
#define INTAKE_IN_BUTTON 7
#define INTAKE_OUT_BUTTON 8
#define INTAKE_ACTUATE_OUT_BUTTON 9
#define INTAKE_ACTUATE_IN_BUTTON 10

//BallFeeder and Shooter Buttons
#define SHOOT_BUTTON 11
#define SHOOTER_OFF_BUTTON 12

#define SHOOT_FROM_HOPPER 14
#define SHOOT_FROM_CENTER_GEAR 15
#define SHOOT_FROM_SIDE_GEAR 16
#define SHOOT_FROM_LOADING_ZONE 13
#define FEEDER_REVERSE 13
#define AGITATOR_REVERSE 14

//Climber Buttons
#define UNLOCK_INTAKE_BUTTON 17
#define LOCK_INTAKE_BUTTON 17
#define CLIMB_BUTTON 9

//Turret
//#define TURRET_UPPER_SOFT_STOP 3.7314814815 //Programming Bot
//#define TURRET_LOWER_SOFT_STOP -3.7314814815 //Programming Bot
#define TURRET_UPPER_SOFT_STOP 2.5
#define TURRET_LOWER_SOFT_STOP -5.5
#define MANUAL_CONTROL_AXIS 2
#define TURRET_JOYSTICK_DEADBAND 0.1
#define MANUAL_OVERRIDE_BUTTON 2
#define PREDICTIVE_SEEK_BUTTON 11

//Shooter
#define HOOD_UPPER_SOFT_STOP 1
#define HOOD_LOWER_SOFT_STOP 0

//Shooter
#define GEAR_UPPER_SOFT_STOP 0.175
#define GEAR_LOWER_SOFT_STOP -0.3

#endif /* SRC_UTILITIES_GLOBALDEFINES_H_ */
