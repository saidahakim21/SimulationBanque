#include "Client.hpp"

/**
 * Constructor for class Client
 * @param aT       time of client's arrival
 * @param b intance object of Bank
 */
Client::Client(double aT, Bank* b){
    arrivalTime = aT;
    bank = b;
}

/**
 * getter for arrival time of the client
 * @return double
 */
double Client::getArrivalTime() {
    return this->arrivalTime;
}

