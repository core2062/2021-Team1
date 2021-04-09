#include "ThreeShotAutonRoutine.h"

ThreeShotRoutine::ThreeShotRoutine() : COREAuton("Three Shot Routine") {}

void ThreeShotRoutine::AddNodes() {
    driveNode = new Node(7000, new DriveAction(BACKWARD));
    shotOneOnNode = new Node(5, new LaunchAction(LAUNCHER_ON));
    delayShotOneNode = new Node(shotDelayTime, new DelayAction());
    shotOneOffNode = new Node(5, new LaunchAction(LAUNCHER_OFF));
    delayOneNode = new Node(delayTime, new DelayAction());
    conveyOneOnNode = new Node(5, new ConveyorAction(CONVEYOR_ON));
    delayConveyOneNode = new Node(conveyDelayTime, new DelayAction());
    conveyOneOffNode = new Node(5, new ConveyorAction(CONVEYOR_OFF));
    delayConveyShotOneNode = new Node(conveyToShotDelayTime, new DelayAction());
    shotTwoOnNode = new Node(5, new LaunchAction(LAUNCHER_ON));
    delayShotTwoNode = new Node(shotDelayTime, new DelayAction());
    shotTwoOffNode = new Node(5, new LaunchAction(LAUNCHER_OFF));
    delayTwoNode = new Node(delayTime, new DelayAction());
    conveyTwoOnNode = new Node(5, new ConveyorAction(CONVEYOR_ON));
    delayConveyTwoNode = new Node(conveyDelayTime, new DelayAction());
    conveyTwoOffNode = new Node(5, new ConveyorAction(CONVEYOR_OFF));
    delayConveyShotTwoNode = new Node(conveyToShotDelayTime, new DelayAction());
    shotThreeOnNode = new Node(5, new LaunchAction(LAUNCHER_ON));
    delayShotThreeNode = new Node(0.5, new DelayAction());
    shotThreeOffNode = new Node(5, new LaunchAction(LAUNCHER_OFF));
    AddFirstNode(driveNode);
    driveNode->AddNext(shotOneOnNode);
    shotOneOnNode->AddNext(delayShotOneNode);
    delayShotOneNode->AddNext(shotOneOffNode);
    shotOneOffNode->AddNext(delayOneNode);
    delayOneNode->AddNext(conveyOneOnNode);
    conveyOneOnNode->AddNext(delayConveyOneNode);
    delayConveyOneNode->AddNext(conveyOneOffNode);
    conveyOneOffNode->AddNext(delayConveyShotOneNode);
    delayConveyShotOneNode->AddNext(shotTwoOnNode);
    shotTwoOnNode->AddNext(delayShotTwoNode);
    delayShotTwoNode->AddNext(shotTwoOffNode);
    shotTwoOffNode->AddNext(delayTwoNode);
    delayTwoNode->AddNext(conveyTwoOnNode);
    conveyTwoOnNode->AddNext(delayConveyTwoNode);
    delayConveyTwoNode->AddNext(conveyTwoOffNode);
    conveyTwoOffNode->AddNext(delayConveyShotTwoNode);
    delayConveyShotTwoNode->AddNext(shotThreeOnNode);
    shotThreeOnNode->AddNext(delayShotThreeNode);
    delayShotThreeNode->AddNext(shotThreeOffNode);
}
