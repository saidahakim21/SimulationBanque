/*********************************
 *
 * Renaud Déniel
 *
 *********************************/

#include "Cashier.hpp"

using namespace std;

Cashier::Cashier(): currentClient(Client(-1, nullptr)) {
    number = -1;
    averageServiceTime = -1;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
    bank = nullptr;
}

Cashier::Cashier(double averageTime, int n, Bank* b): currentClient(Client(-1, b)) {
    number = n;
    averageServiceTime = averageTime;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
    bank = b;
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

void Cashier::serve(Client c) {
    clientNb ++;
    servingClient = true;
    currentClient = c;
    double duration = Poisson::next(averageServiceTime);
    double eventTime = bank->getTime()+duration;

    // For stats
//    bank->addWaitingTime(duration);
    occupationTime += duration;

    // Add event to stop serving the client
    bank->addEvent(new CashierRelease(eventTime, this, number, c, bank));
}

void Cashier::wait() {
    servingClient = false;
    currentClient = Client(-1, nullptr);
}

double Cashier::occupationRate() {
    return (occupationTime/bank->getTime());
}
