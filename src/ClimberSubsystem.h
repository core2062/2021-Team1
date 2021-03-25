#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

class ClimberSubsystem : public CORESubsystem {
public:
    ClimberSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void initTalons();
    int STILT_RISE_DISTANCE;
private:
    TalonSRX m_stilt1;
    TalonSRX m_stilt2;
    bool m_stiltsEngaged = false;
    double m_encoder1StartUpPosition;
    double m_encoder2StartUpPosition;
   
};
