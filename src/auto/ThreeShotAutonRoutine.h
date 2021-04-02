#pragma once

#include <string>
#include <CORERobotLib.h>
#include "DriveAction.h"
#include "ConveyorAction.h"
#include "DelayAction.h"
#include "LaunchAction.h"
// #include "AutonActionTest.h"

using namespace CORE;
using namespace std;

class ThreeShotRoutine: public COREAuton {
public:
    ThreeShotRoutine();
    void AddNodes() override;
private:
    Node * driveNode;
    Node * delayNode;

};
