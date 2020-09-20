#include "Depart.hpp"

using namespace std;

/**
 * Constructor with parameters:
 * @param t     time of the event
 * @param b pointer to the event
 */
Depart::Depart(double time, Cashier* ca, int n, Client cl, Simulation* simulation): Event(time,simulation), _cashier(ca), _client(cl) {
    number = n;
}

void Depart::process() {
    Bank* bank =  _simulation->getBank(); 
    if(bank->getWaitingList()[number].size()>0) {
        cout << "Cashier " << _cashier->getNumber() << " serves next client" << endl;
        // pop the first client from waiting list
        Client c = bank->getWaitingList()[number].removeFirst();
        //for the stats
        bank->addWaitingTime(_simulation->getTime() - c.getArrivalTime());
        // serving the client
        _cashier->serve(c, _simulation);
    }
        // otherwise, cashier waits for a new client
    else {
        cout << "Cashier " << _cashier->getNumber() << " waits" << endl;
        _cashier->wait();
    }
    
}