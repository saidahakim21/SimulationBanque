/*********************************
 *
 * Renaud Déniel
 *
 *********************************/

#include "Cashier.hpp"

using namespace std;

Cashier::Cashier(): _currentClient(Client(-1, nullptr)) {
    _number = -1;
    _averageServiceTime = -1;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
    _bank = nullptr;
}

Cashier::Cashier(double averageTime, int n, Bank* b): _currentClient(Client(-1, b)) {
    _number = n;
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
    _bank = b;
}

Cashier::~Cashier() = default;

double Cashier::averageServiceTime(){
    return _averageServiceTime;
}

int Cashier::clientNb(){
    return _clientNb;
}

int Cashier::number() {
    return _number;
}

bool Cashier::isFree() {
    return !_servingClient;
}

void Cashier::serve(Client c) {
    _clientNb ++;
    _servingClient = true;
    _currentClient = c;
    double duration = Poisson::next(_averageServiceTime);
    double eventTime = _bank->time()+duration;

    // For stats
//    _bank->addWaitingTime(duration);
    _occupationTime += duration;

    // Add event to stop serving the client
    _bank->addEvent(new CashierRelease(eventTime, this, _number, c, _bank));
}

void Cashier::wait() {
    _servingClient = false;
    _currentClient = Client(-1, nullptr);
}

double Cashier::occupationRate() {
    return (_occupationTime/_bank->time());
}
