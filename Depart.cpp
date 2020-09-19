/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#include "Depart.hpp"

using namespace std;

/**
 * Constructor with parameters:
 * @param t     time of the event
 * @param ca pointer to the freed cashier
 * @param n number of cashier
 * @param cl the served client
 * @param b pointer to the bank
 */
Depart::Depart(double t, Cashier* ca, int n, Client cl, Bank* b): Event(t, b), _cashier(ca), _client(cl) {
    _number = n;
}

void Depart::process() {
    if(_bank->waitingList()[_number].size()>0) {
        cout << "Cashier " << _cashier->number() << " serves next client" << endl;
        // pop the first client from waiting list
        Client c = _bank->waitingList()[_number].removeFirst();
        //for the stats
        _bank->addWaitingTime(_bank->time() - c.arrivalTime());
        // serving the client
        _cashier->serve(c);
    }
    // otherwise, cashier waits for a new client
    else {
        cout << "Cashier " << _cashier->number() << " waits" << endl;
        _cashier->wait();
    }
}
