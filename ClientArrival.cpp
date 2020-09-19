/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#include "ClientArrival.hpp"

using namespace std;

/* Constructor with parameters:
- t     time of the event
- b     pointer to the bank
*/
ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {}

/* Process of the client arrival event */
void ClientArrival::process() {
    // Create client (using average time)
    Client client(this->time, this->bank);

    Cashier* cashier = this->bank->freeCashier();
    // If there isn't any free cashier, add client to the queue
    if(cashier == nullptr) {
        WaitingList* wl = this->bank->getWaitingList();
        wl->add(client);
        cout << "New client waits at line " << wl->getNumber() << endl;
    }
    // Else, have the cashier serve the client
    else {
        // For stats at the end of the simulation
        this->bank->addWaitingTime(0);

        cout << "New client served by " << cashier->getNumber() << endl;
        cashier->serve(client); 
    }

    // Create next client arrival event if it doesn't exceed the expected time of the simulation
    double nextTime = this->bank->getTime()+Poisson::next(this->bank->getAverageArrivalTime());
    if(nextTime < this->bank->getExpectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, this->bank);
        this->bank->addEvent(ca);
    }
}
