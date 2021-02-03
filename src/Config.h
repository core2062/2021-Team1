#pragma once
/*
 * Port ID Conventions
 * 
 * Ports 0-3: PCMs
 * Ports 4-7: Drivetrain Talons
 * Ports 8-9: Drivetrain Shifters
 * Ports 10-20: Other Solenoids
 * Ports 21-30: Other Talons
 * Ports 31-50: Any additional ports
 * 
 */

/* PCM Ports */
#define PCM 0

/* Drive ports */
#define RIGHT_FRONT_PORT 4
#define RIGHT_BACK_PORT 5
#define LEFT_FRONT_PORT 6
#define LEFT_BACK_PORT 7

/* Shifters */
#define LEFT_DRIVE_SHIFTER_LOW_GEAR_PORT 8
#define RIGHT_DRIVE_SHIFTER_LOW_GEAR_PORT 8
#define LEFT_DRIVE_SHIFTER_HIGH_GEAR_PORT 9
#define RIGHT_DRIVE_SHIFTER_HIGH_GEAR_PORT 9

/* Launcher Ports */
#define LAUNCHER_PORT_RETRACTED 10 
#define LAUNCHER_PORT_EXTENDED 11

/* Intake and Conveyor Port(s) */
#define CONVEYOR_PORT_1 23

/* Climber port */
#define CLIMBER_1_PORT 21
#define CLIMBER_2_PORT 22

/* STILTS PORTS */
#define STILT_1_PORT 1
#define STILT_2_PORT 1

#define STILT_ENGAGE_BUTTON COREJoystick::JoystickButton::LEFT_BUTTON

// in encoder ticks
#define STILT_RISE_DISTANCE 
