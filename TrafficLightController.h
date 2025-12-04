#include <string>
using namespace std;

enum light {RED, YELLOW, GREEN};
enum state {S0, S1, S2, S3, S4};

class TrafficLightController {
private:
    bool Ta, minTimeA, maxTimeA, Tb, minTimeB, maxTimeB;   // inputs
    light La, Lb;    // outputs (moore)
    state current_state;
    int a_count, b_count; //counters for La and Lb
    void changeState();
    void incrementCount();
    void updateOutputs(); // update outputs (and count) after changing state
    string lightToString(light l);
public:
    TrafficLightController();
    void readInputs(bool trafficA, bool trafficB);
    void printState();
};
