#include "ThreeShotAutonRoutine.h"

ThreeShotRoutine::ThreeShotRoutine() : COREAuton("Three Shot Routine") {}

void ThreeShotRoutine::AddNodes() {
    driveNode = new Node(5, new DriveAction(FORWARD));
    AddFirstNode(driveNode);
}
