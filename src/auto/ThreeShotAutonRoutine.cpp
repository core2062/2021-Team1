#include "ThreeShotAutonRoutine.h"

ThreeShotRoutine::ThreeShotRoutine() : COREAuton("Three Shot Routine") {}

void ThreeShotRoutine::AddNodes() {
    driveNode = new Node(5, new DriveAction(FORWARD));
    launchOnNode = new Node(5, new LaunchAction(LAUNCHER_ON));
    delayLaunchNode = new Node(1, new DelayAction());
    launchOffNode = new Node(5, new LaunchAction(LAUNCHER_OFF));
    conveyorOnNode = new Node(5, new ConveyorAction(CONVEYOR_ON));
    delayConveyorNode = new Node(1, new DelayAction());
    conveyorOffNode = new Node(5, new ConveyorAction(CONVEYOR_OFF));
    AddFirstNode(driveNode);
    driveNode->AddNext(launchOnNode);
    launchOnNode->AddNext(delayLaunchNode);
    delayLaunchNode->AddNext(launchOffNode);
    launchOffNode->AddNext(conveyorOnNode);
    conveyorOnNode->AddNext(delayConveyorNode);
    delayConveyorNode->AddNext(conveyorOffNode);
    conveyorOffNode->AddNext(launchOnNode);
    launchOnNode->AddNext(delayLaunchNode);
    delayLaunchNode->AddNext(launchOffNode);
    launchOffNode->AddNext(conveyorOnNode);
    conveyorOnNode->AddNext(delayConveyorNode);
    delayConveyorNode->AddNext(conveyorOffNode);
    conveyorOffNode->AddNext(launchOnNode);
    launchOnNode->AddNext(delayLaunchNode);
    delayLaunchNode->AddNext(launchOffNode);
}
