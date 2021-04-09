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
    Node * conveyOneOnNode;
    Node * conveyTwoOnNode;
    Node * conveyOneOffNode;
    Node * conveyTwoOffNode;
    Node * delayOneNode;
    Node * delayTwoNode;
    Node * delayShotOneNode;
    Node * delayShotTwoNode;
    Node * delayShotThreeNode;
    Node * delayConveyOneNode;
    Node * delayConveyTwoNode;
    Node * delayConveyShotOneNode;
    Node * delayConveyShotTwoNode;
    Node * shotOneOnNode;
    Node * shotTwoOnNode;
    Node * shotThreeOnNode;
    Node * shotOneOffNode;
    Node * shotTwoOffNode;
    Node * shotThreeOffNode;
    double shotDelayTime = 0.5;
    double delayTime = 1.5;
    double conveyDelayTime = 0.1;
    double conveyToShotDelayTime = 0.25;
};
