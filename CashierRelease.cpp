
#include "CashierRelease.hpp"

using namespace std;

CashierRelease::CashierRelease(double t, Cashier* ca, int n, Client cl, Bank* b): Event(t, b), cashier(ca), client(cl) {
    number = n;
}

/* Process of the CashierRelease event */
void CashierRelease::process() {
    // If waiting list isn't empty
    if(bank->waitingList.size()>0) {
        cout << "Cashier " << cashier->number() << " serves next client" << endl;
        // Take 1st client waiting in the right queue
        Client c = bank->waitingList.removeFirst();

        // Stats
        bank->addWaitingTime(bank->getTime() - c.arrivalTime());

        // Have the cashier serve him
        cashier->serve(c);
    }
    // Else, cashier waits
    else {
        cout << "Cashier " << cashier->number() << " waits" << endl;
        cashier->wait();
    }
}
