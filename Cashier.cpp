#include "Cashier.hpp"

using namespace std;
/**
 * default constructor for class Cahsier
 * initialise a new client .
 */
Cashier::Cashier(): currentClient(Client(-1)) {
    number = -1;
    averageServiceTime = -1;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
}

/**
 * constructor for class Cashier
 * @param averageTime average service time for this cashier
 * @param n the number of the Cashier, used as an ID
 */
Cashier::Cashier(double averageTime, int n): currentClient(Client(-1)) {
    number = n;
    averageServiceTime = averageTime;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
}

Cashier::~Cashier() = default;

double Cashier::getAverageServiceTime(){
    return averageServiceTime;
}

int Cashier::getClientNb(){
    return clientNb;
}

int Cashier::getNumber() {
    return number;
}

bool Cashier::isFree() {
    return !servingClient;
}

void Cashier::serve(Client c, Simulation* simulation) {
    
    clientNb ++;
    servingClient = true;
    currentClient = c;
    double duration = Poisson::next(averageServiceTime);
    occupationTime += duration;
    double eventTime =  simulation->getTime() + duration;

    // Add event to stop serving the client
    simulation->addEvent(new Depart(eventTime, this, number, c, simulation));
    
}

void Cashier::wait() {
    servingClient = false;
    currentClient = Client(-1);
}

double Cashier::getOccupationRate(double simulationDuration) {
    
    return (occupationTime/simulationDuration);
}
