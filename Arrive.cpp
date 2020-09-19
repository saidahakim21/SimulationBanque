#include "Arrive.hpp"

using namespace std;


/**
 * constructor for Arrive class
 * @param t time of arrival Event
 * @param b instance of Bank
 */
 Arrive::Arrive(double t, Bank* b): Event(t, b) {}

void Arrive::process() {
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
        Arrive *ca = new Arrive(nextTime, bank);
        bank->addEvent(ca);
    }
}
