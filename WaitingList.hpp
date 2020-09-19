/*********************************
 *
 * Renaud Déniel et
 *
 *********************************/

#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP

#include <iostream>
#include <deque>

#include "Bank.hpp"
#include "Client.hpp"

class Client;

class WaitingList{
protected:
    int number;
    int _currClients;
    int _maxClients;

    double _lastModifTime;
    double _timeClientSum;

    Bank* bank;

    std::deque<Client> _clientList;

    void addToAverage();

public:
    WaitingList();
    explicit WaitingList(Bank*);
    ~WaitingList();

    void add(Client);
    bool isEmpty();
    int size();
    Client removeFirst();
    int getNumber();

    int maxLength();
    double averageLength();
};

#endif
