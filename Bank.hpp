/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#ifndef __BANK_HPP
#define __BANK_HPP

#include <iostream>
#include <set>
#include <vector>

#include "Cashier.hpp"
#include "ClientArrival.hpp"
#include "SED.hpp"
#include "Queue.hpp"

class Cashier;

class Bank: public SED {
protected:
    double arrivalTimeInterval;
    double _expectedTime;
    int _cashierNb;

    Cashier* cashiers;

    // Variable used to get stats about the simulation
    std::vector<double> _waitingTimes;

public:
    Bank(double, double, int, double, double*);
    ~Bank() override;

    void start() override;

    double averageArrivalTime();
    double expectedTime();
    int cashierNb();
    Queue waitingList = new Queue(this);

    Cashier* getAvailableCashier();

    void addWaitingTime(double);
    double realDuration();

    void displayStats();
};

#endif
