#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : m_stilt1(STILT_1_PORT),
                                       m_stilt2(STILT_2_PORT) {

                                      }

void ClimberSubsystem::robotInit() {
    initTalons();
}

void ClimberSubsystem::teleopInit() {
    initTalons();
}

void ClimberSubsystem::teleop() {

}

void ClimberSubsystem::initTalons(){

}
