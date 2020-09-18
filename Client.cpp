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
    _arrivalTime = arrivalTime;
    _bank = bank;
}

/* Returns arrival time of the client */
double Client::arrivalTime() {
    return _arrivalTime;
}

