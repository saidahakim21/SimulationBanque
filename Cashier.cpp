#include "Cashier.hpp"

using namespace std;

/**
 * empty consntructor for class Cashier
 */
Cashier::Cashier() : currentClient(Client(-1, nullptr)) {
    number = -1;
    averageServiceTime = -1;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
    bank = nullptr;
}

/**
 * Constructor for Cashier
 * @param averageTime average service time for this cashier
 * @param n number of the cashier, used as ID
 * @param b instance of the Bank object
 */
Cashier::Cashier(double averageTime, int n, Bank *b) : currentClient(Client(-1, b)) {
    number = n;
    averageServiceTime = averageTime;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
    bank = b;
}

Cashier::~Cashier() = default;

/**
 * getter for average service time
 * @return double
 */
double Cashier::getAverageServiceTime() {
    return averageServiceTime;
}

/**
 * getter for number of clients served
 * @return int
 */
int Cashier::getClientNb() {
    return clientNb;
}

/**
 * getter for the number of the cashier
 * @return int
 */
int Cashier::getNumber() {
    return number;
}

/**
 * getter to check wheter Cashier is free
 * @return boolean
 */
bool Cashier::isFree() {
    return !servingClient;
}

/**
 * serve a Client object
 * @param c instance of Client object to be served
 */
void Cashier::serve(Client c) {
    clientNb++;
    servingClient = true;
    currentClient = c;
    double duration = Poisson::next(averageServiceTime);
    double eventTime = bank->getTime() + duration;

    // For stats
//    bank->addWaitingTime(duration);
    occupationTime += duration;

    // Add event to stop serving the client
    bank->addEvent(new Depart(eventTime, this, number, c, bank));
}

/**
 * reset obeject settings and  wait until next client
 */
void Cashier::wait() {
    servingClient = false;
    currentClient = Client(-1, nullptr);
}

/**
 * @return calculated occupation rate in the simulation
 */
double Cashier::getOccupationRate() {
    return (occupationTime / bank->getTime());
}
