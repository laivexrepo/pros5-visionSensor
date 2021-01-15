#ifndef PORT_DEF_H_
#define PORT_DEF_H_

//Drive base motors
#define LEFT_MOTOR_PORT  10     // primary drive motors in drive train
#define RIGHT_MOTOR_PORT  1

// When you have two motors per side in your drive train, add second set of
// motor port definitions
#define LEFT_MOTOR_PORT_2  9    // when two motors per side drive train
#define RIGHT_MOTOR_PORT_2  2

// Lift motors
#define LIFT_MOTOR_PORT 8

// Claw (intake motors)
#define CLAW_MOTOR_PORT_1 3

// If two clawmotors uncomment below statement - it is also assumed that they
// both run in opposite directions - so watch for the motor definition
// statement in globals.c
//#define CLAW_MOTOR_PORT_2 4

// tray motors
#define TRAY_MOTOR_PORT 16

// GYRO / IMU
#define IMU_PORT 11

// New PORT extender
#define EXTENDER_PORT 18

// New Distance Sensor
#define DISTANCE_PORT 19

// New rotation Sensor
#define ROTATION_PORT 13

// New optical Sensor
#define OPTICAL_PORT 12

// ----------- Radio and Controllers ---------------
//#define VEX_RADIO 21

// ------------ Vision Sensors ---------------------
#define VISION_PORT 14
#define VISION_CAMERA 21

// ----------- LEGACY port assignments ------------
#define BUTTON_SWITCH_PORT 1
#define QUAD1_TOP_PORT 3
#define QUAD1_BOTTOM_PORT 4


#endif
