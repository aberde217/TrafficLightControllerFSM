#include "TrafficLightController.h"
#include <iostream>
using namespace std;

TrafficLightController::TrafficLightController() {
    La = Lb = RED;
    current_state = S0; // Initial state (never returns here)
    Ta = Tb = minTimeA = minTimeB = maxTimeA = maxTimeB = false;
    a_count = b_count = 0;
}

void TrafficLightController::readInputs(bool trafficA, bool trafficB) {
    this->Ta = trafficA;
    this->Tb = trafficB;
    incrementCount();
    changeState();
    updateOutputs();
}

void TrafficLightController::incrementCount() {
    if (current_state == S1) {
        if (a_count == 3)
            minTimeA = true;
        else if (a_count == 9)
            maxTimeA = true;
        a_count++;
    }
    if (current_state == S3) {
        if (b_count == 3)
            minTimeB = true;
        if (b_count == 9)
            maxTimeB = true;
        b_count++;
    }
}

void TrafficLightController::changeState() {
    switch (current_state) {
        case S1:
            if (!minTimeA)
                current_state = S1;
            else if (minTimeA && Ta && !maxTimeA)
                current_state = S1;
            else
                current_state = S2;
        break;
        case S2:
            current_state = S3;
        break;
        case S3:
            if (!minTimeB)
                current_state = S3;
            else if (minTimeB && Tb && !maxTimeB)
                current_state = S3;
            else
                current_state = S4;
        break;
        case S4:
            current_state = S1;
        break;
        default:   // initial state, S0
            current_state = S1;
        break;
    }
}

void TrafficLightController::updateOutputs() {
    switch (current_state) {
        case S1:
            La = GREEN;
            Lb = RED;
        break;
        case S2:
            a_count = 0;
            minTimeA = maxTimeA = false;
            La = YELLOW;
            Lb = RED;
        break;
        case S3:
            La = RED;
            Lb = GREEN;
        break;
        case S4:
            b_count = 0;
            minTimeB = maxTimeB = false;
            La = RED;
            Lb = YELLOW;
        break;
        default:
            La = Lb = RED;
        break;
    }
}

string TrafficLightController::lightToString(light l) {
    if (l == RED) return "RED";
    else if (l == YELLOW) return "YELLOW";
    else return "GREEN";
}

void TrafficLightController::printState() {
    if (La == GREEN)
        cout << "La (N and S): " << lightToString(La) << "   (GREEN TIME LEFT: " << (10 - a_count) << ")\tLb (E and W): " << lightToString(Lb) << endl;
    else if (Lb == GREEN)
        cout << "La (N and S): " << lightToString(La)  << "\tLb (E and W): " << lightToString(Lb) << "   (GREEN TIME LEFT: " << (10 - b_count) << ")" << endl;
    else cout << "La (N and S): " << lightToString(La) << "\tLb (E and W): " << lightToString(Lb) << endl;
}
