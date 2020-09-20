#include "ClientArrival.hpp"

using namespace std;

/**
 * @param time
 * @param simulation
 */
 ClientArrival::ClientArrival(double time, Simulation* simulation): Event(time,simulation) {}

/* Process of the client arrival event */
void ClientArrival::process() {
    
    // Create client (using average time)
    Client client(time);

    Bank* bank = _simulation->getBank(); 

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
        cashier->serve(client, _simulation); 
    }    
}
