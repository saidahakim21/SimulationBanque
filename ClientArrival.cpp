#include "ClientArrival.hpp"

using namespace std;


/**
 *
 * @param t
 * @param b
 */
 ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {}

/* Process of the client arrival event */
void ClientArrival::process() {
    // Create client (using average time)
    Client client(time, bank);

    Cashier* cashier = bank->freeCashier();
    // If there isn't any free cashier, add client to the queue
    if(cashier == nullptr) {
        WaitingList* wl = bank->getWaitingList();
        wl->add(client);
        cout << "New client waits at line " << wl->getNumber() << endl;
    }
    // Else, have the cashier serve the client
    else {
        // For stats at the end of the simulation
        bank->addWaitingTime(0);

        cout << "New client served by " << cashier->getNumber() << endl;
        cashier->serve(client); 
    }

    // Create next client arrival event if it doesn't exceed the expected time of the simulation
    double nextTime = bank->getTime()+Poisson::next(bank->getAverageArrivalTime());
    if(nextTime < bank->getExpectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, bank);
        bank->addEvent(ca);
    }
}
