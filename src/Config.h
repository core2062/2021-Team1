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
#define PCM 2

/* Drive ports */
#define RIGHT_FRONT_PORT 5
#define RIGHT_BACK_PORT 7
#define LEFT_FRONT_PORT 4
#define LEFT_BACK_PORT 6

/* Shifters */
#define LEFT_DRIVE_SHIFTER_LOW_GEAR_PORT 8
#define RIGHT_DRIVE_SHIFTER_LOW_GEAR_PORT 8
#define LEFT_DRIVE_SHIFTER_HIGH_GEAR_PORT 9
#define RIGHT_DRIVE_SHIFTER_HIGH_GEAR_PORT 9

/* Launcher Ports */
#define PNEUMATIC_LAUNCHER_SYSTEM_OPEN_1 2
#define PNEUMATIC_LAUNCHER_SYSTEM_OPEN_2 3

/* Intake and Conveyor Port(s) */
#define CONVEYOR_PORT_1 25
#define TILT_PORT 26

/* Climber port */
#define CLIMBER_1_PORT 21
#define CLIMBER_2_PORT 22
#define CLIMBER_1_PORT_GEAR 23
#define CLIMBER_2_PORT_GEAR 24
