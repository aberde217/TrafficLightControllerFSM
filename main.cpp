#include <iostream>
#include "TrafficLightController.h"
using namespace std;


int main() {
    TrafficLightController controller;
    bool inputsForSim[21][2] = {
        {false, false}, {true, false}, {true, false}, {true, true}, {true, false}, {true, false},
            {true, true}, {true, false}, {true, false}, {true, true}, {true, true}, {true, true}, {true, true},
                {true, false}, {true, true}, {true, true}, {true, false}, {true, true}, {false, true},  {false, false}, {false, false}};
    for (int i = 0; i < 21; i++) {
        controller.readInputs(inputsForSim[i][0], inputsForSim[i][1]);
        controller.printState();
    }

    return 0;
}
