/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#include "WaitingList.hpp"

/* Constructor with the index in the array of waiting lists in Bank */
WaitingList::WaitingList(Bank* bank) {
    _currClients = 0;
    _maxClients = 0;
//    _lastModifTime = bank->time();
    _lastModifTime = 0;
    _timeClientSum = 0;

    _bank = bank;
}

WaitingList::~WaitingList() = default;

/* Add Client to WaitingList */
void WaitingList::add(Client c) {
    addToAverage();

    _currClients ++;
    if(_currClients > _maxClients) {
        _maxClients = _currClients;
    }
    _clientList.push_back(c);
}

/* Remove the first waiting Client of the queue and returns it */
Client WaitingList::removeFirst() {
    addToAverage();

    _currClients --;
    Client c = _clientList.front();
    _clientList.pop_front();
    return c;
}

/* Returns if the queue is empty */
bool WaitingList::isEmpty(){
    return _clientList.empty();
}

/* Returns the size of the queue */
int WaitingList::size() {
    return _clientList.size();
}

/* Returns the index of the queue in the Bank */
int WaitingList::number() {
    return _number;
}

/* Function to add (nb of client) * (time passed with his nb of clients) to the curren sum */
void WaitingList::addToAverage() {
    double timeDiff = _bank->time() - _lastModifTime;
    _timeClientSum += _currClients*timeDiff;
    _lastModifTime = _bank->time();
}

/* Returns the max length reached by the queue */
int WaitingList::maxLength() {
    return _maxClients;
}

/* Returns the number of client waiting in average in the queue */
double WaitingList::averageLength() {
    addToAverage();
    return _timeClientSum / _bank->time();
}
