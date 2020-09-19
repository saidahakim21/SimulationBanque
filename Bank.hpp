#ifndef __BANK_HPP
#define __BANK_HPP

#include <iostream>
#include <set>
#include <vector>

#include "Cashier.hpp"
#include "Arrive.hpp"
#include "SED.hpp"
#include "WaitingList.hpp"

class Cashier;
class WaitingList;
/**
 * A class for a bank illustration.
 */
class Bank: public SED {
protected:
    /// the average time until next client arrival
    double averageArrivalTime;
    /// the expected time for the simulation
    double expectedTime;
    /// number of cashiers
    int cashierNb;

    /// a pointer to the cashiers
    Cashier* cashiers;
    /// a poinnter to the waiting list
    WaitingList* waitingList;

    /// a vector for saving simulations stats
    std::vector<double> waitingTimes;

public:
    Bank(double, double, int, double, double*);
    ~Bank() override;
    /**
     * run the simulation, itirate over the events and incrementing time
     */
    void run() override;

    /**
     * getter for average interval till next arrival client
     * @return double
     */
    double getAverageArrivalTime();
    /**
     * getter for the expected total time of the simulation
     * @return double
     */
    double getExpectedTime();
    /**
     * getter for the number of cashiers in the bank
     * @return int
     */
    int getCashierNb();

    /**
     * fetch and return the first free Cashier available
     * @return pointer to Cashier
     */
    Cashier* freeCashier();
    /**
     * getter for the waiting list
     * @return a pointer to WaitingList object
     */
    WaitingList* getWaitingList();

    /**
     * adding a waiting time to the actual current time of the simulationn
     * @param t time to add
     */
    void addWaitingTime(double);
    /**
     * calculates and return the real duration of the simulation
     * @return double
     */
    double realDuration();

    /**
     * displays the simulation statistics on console
     */
    void displayStats();
};

#endif
