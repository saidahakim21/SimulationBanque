#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include <iostream>

#include "Bank.hpp"
#include "Depart.hpp"
#include "Client.hpp"
#include "Simulation.hpp"

class Simulation; 

/**
 * a class that illustrates a cashier object
 */
class Cashier{
protected:
    int number;
    double averageServiceTime;
    Client currentClient;
    bool servingClient;
    int clientNb;
    double occupationTime;

public:
    /**
     * default empty constructor for a Cahsier class
     */
    Cashier();
    explicit Cashier(double, int);
    ~Cashier();

    /**
     * getter for the average service time of the cashier
     * @return double
     */
    double getAverageServiceTime();
    /**
     * getter of the client number
     * @return int
     */
    int getClientNb();
    /**
     * getter of the cashier number
     * @return int
     */
    int getNumber();

    /**
     * checks whether the cashier is free or not
     * @return boolean, true if free, false otherwie
     */
    bool isFree();
    void serve(Client, Simulation*);
    /**
     * wait until next client arrival
     */
    void wait();
    /**
     * calculate and return the occupation rate during the simulation
     * @param simulationDuration the actual duration of the simulaiton
     * @return double
     */
    double getOccupationRate(double simulationDuration);
};

#endif
