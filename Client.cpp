/*********************************
 *
 * Renaud Déniel
 *
 *********************************/

#include "Client.hpp"

/* Constructor with parameters:
- arrivalTime       time of arrival of the client
- bank              pointer to the Bank
*/
Client::Client(double arrivalTime, Bank* bank){
    arrivalTime = arrivalTime;
    bank = bank;
}

/* Returns arrival time of the client */
double Client::getArrivalTime() {
    return arrivalTime;
}

