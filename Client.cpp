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
Client::Client(double aT, Bank* b){
    arrivalTime = aT;
    bank = b;
}

/* Returns arrival time of the client */
double Client::getArrivalTime() {
    return this->arrivalTime;
}

