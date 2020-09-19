#include "Cashier.hpp"

using namespace std;

Cashier::Cashier() : currentClient(Client(-1, nullptr)) {
    number = -1;
    averageServiceTime = -1;
    clientNb = 0;
    this->servingClient = false;
    occupationTime = 0;
    bank = nullptr;
}

Cashier::Cashier(double averageTime, int n, Bank *b) : currentClient(Client(-1, b)) {
    number = n;
    averageServiceTime = averageTime;
    clientNb = 0;
    servingClient = false;
    occupationTime = 0;
    bank = b;
}

Cashier::~Cashier() = default;

double Cashier::getAverageServiceTime() {
    return averageServiceTime;
}

int Cashier::getClientNb() {
    return this->clientNb;
}

int Cashier::getNumber() {
    return number;
}

bool Cashier::isFree() {
    return !this->servingClient;
}

void Cashier::serve(Client c) {
    this->clientNb++;
    this->servingClient = true;
    this->currentClient = c;
    double duration = Poisson::next(this->averageServiceTime);
    double eventTime = bank->getTime() + duration;

    // For stats
//    bank->addWaitingTime(duration);
    this->occupationTime += duration;

    // Add event to stop serving the client
    bank->addEvent(new Depart(eventTime, this, this->number, c, bank));
}

void Cashier::wait() {
    this->servingClient = false;
    this->currentClient = Client(-1, nullptr);
}

double Cashier::getOccupationRate() {
    return (this->occupationTime / bank->getTime());
}
