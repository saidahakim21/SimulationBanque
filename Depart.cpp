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
    number = n;
}

void Depart::process() {
    if(bank->getWaitingList()[number].size()>0) {
        cout << "Cashier " << _cashier->getNumber() << " serves next client" << endl;
        // pop the first client from waiting list
        Client c = bank->getWaitingList()[number].removeFirst();
        //for the stats
        bank->addWaitingTime(bank->getTime() - c.getArrivalTime());
        // serving the client
        _cashier->serve(c);
    }
        // otherwise, cashier waits for a new client
    else {
        cout << "Cashier " << _cashier->getNumber() << " waits" << endl;
        _cashier->wait();
    }
}