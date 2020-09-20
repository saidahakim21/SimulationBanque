#include "Cashier.hpp"

using namespace std;

Cashier::Cashier(): _currentClient(Client(-1)) {
    _number = -1;
    _averageServiceTime = -1;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
}

Cashier::Cashier(double averageTime, int n): _currentClient(Client(-1)) {
    _number = n;
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
}

Cashier::~Cashier() = default;

double Cashier::averageServiceTime(){
    return _averageServiceTime;
}

int Cashier::getClientNb(){
    return _clientNb;
}

int Cashier::getNumber() {
    return _number;
}

bool Cashier::isFree() {
    return !_servingClient;
}

void Cashier::serve(Client c, Simulation* simulation) {
    
    _clientNb ++;
    _servingClient = true;
    _currentClient = c;
    double duration = Poisson::next(_averageServiceTime);
    _occupationTime += duration;
    double eventTime =  simulation->getTime() + duration;

    // Add event to stop serving the client
    simulation->addEvent(new Depart(eventTime, this, _number, c, simulation));
    
}

void Cashier::wait() {
    
    _servingClient = false;
    _currentClient = Client(-1);
    
}

double Cashier::getOccupationRate(double simulationDuration) {
    
    return (_occupationTime/simulationDuration);
}
