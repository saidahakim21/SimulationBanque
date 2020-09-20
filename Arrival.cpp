#include "Arrival.hpp"

using namespace std;

/**
 * @param time
 * @param simulation
 */
 Arrival::Arrival(double time, Simulation* simulation): Event(time,simulation) {}

/**
 * process the Event, override of superclass methode
 */
 void Arrival::process() {
    
    // Create client (using average time)
    Client client(time);

    Bank* bank = simulation->getBank();

    Cashier* cashier = bank->freeCashier();
    // If there isn't any free cashier, add client to the queue
    if(cashier == nullptr) {
        Queue* wl = bank->getQueue();
        wl->add(client);
        cout << "New client waits at line " << endl;
    }
    // Else, have the cashier serve the client
    else {
        // For stats at the end of the simulation
        bank->addWaitingTime(0);

        cout << "New client served by " << cashier->getNumber() << endl;
        cashier->serve(client, simulation);
    }    
}
