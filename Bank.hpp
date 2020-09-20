#ifndef __BANK_HPP
#define __BANK_HPP

#include <iostream>
#include <set>
#include <vector>

#include "Cashier.hpp"
#include "ClientArrival.hpp"
#include "DES.hpp"
#include "WaitingList.hpp"

class Cashier;
class WaitingList;
/**
 * A class for a bank illustration.
 */
class Bank{
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
    Bank(double, int, double, double*);
    ~Bank();

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
     * return the Cashiers
     * @return pointer to Cashiers
     */
    Cashier* getCashiers();
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

    void displayStats();
};

#endif
