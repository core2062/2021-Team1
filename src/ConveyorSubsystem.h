#pragma once

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

class ConveyorSubsystem : public CORESubsystem {
public:
    double conveyorSpeed;
    ConveyorSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void initTalons();
    void setMotor(double conveyorSpeed);
 

private: 
    TalonSRX m_conveyorMotor;
};

