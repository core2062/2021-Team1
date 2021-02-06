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

private:
    TalonSRX m_stilt1, m_stilt2, m_stilt1Gear, m_stilt2Gear;
    bool m_stiltsActivated;
    int m_stiltLenthInTicks;
};
