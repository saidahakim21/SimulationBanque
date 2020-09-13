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
    Client client(time, bank);

    Cashier* cashier = bank->getAvailableCashier();
    // If there isn't any free cashier, add client to the sortest queue
    if(cashier == nullptr) {
        bank->waitingList->add(client);
        cout << "New client waits at line " << endl;
    }
    // Else, have the cashier serve the client
    else {
        // For stats at the end of the simulation
        bank->addWaitingTime(0);

        cout << "New client served by " << cashier->getNumber() << endl;
        cashier->serve(client); 
    }

    // Create next client arrival event if it doesn't exceed the expected time of the simulation
    double nextTime = bank->getTime()+Poisson::next(bank->averageArrivalTime());
    if(nextTime < bank->getExpectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, bank);
        bank->addEvent(ca);
    }
}
