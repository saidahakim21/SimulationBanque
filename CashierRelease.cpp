/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#include "CashierRelease.hpp"

using namespace std;

/* Constructor with parameters:
- t     time of the event
- ca    pointer to the cashier finishing to serve the client
- n     number of the cashier, corresponding to the index in the cashier array in the simulation
- cl    client finishing being served
- b     pointer to the Bank
*/
CashierRelease::CashierRelease(double t, Cashier* ca, int n, Client cl, Bank* b): Event(t, b), _cashier(ca), _client(cl) {
    _number = n;
}

/* Process of the CashierRelease event */
void CashierRelease::process() {
    // If waiting list isn't empty
    if(_bank->waitingList()->size()>0) {
        cout << "Cashier " << _cashier->number() << " serves next client" << endl;
        // Take 1st client waiting in the right queue
        Client c = _bank->waitingList()->removeFirst();

        // Stats
        _bank->addWaitingTime(_bank->time() - c.arrivalTime());

        // Have the cashier serve him
        _cashier->serve(c);
    }
    // Else, cashier waits
    else {
        cout << "Cashier " << _cashier->number() << " waits" << endl;
        _cashier->wait();
    }
}
