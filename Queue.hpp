/******************************
 * created by Yacine ZABAT
 ******************************/

#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP

#include <iostream>
#include <deque>

#include "Bank.hpp"
#include "Client.hpp"

class Client;

class Queue{
protected:
    int number;
    int currClients;
    int maxClients;

    double lastModifTime;
    double timeClientSum;

    Bank* bank;

    std::deque<Client> clientList;

    void addToAverage();

public:
    Queue();
    explicit Queue(Bank*);
    ~Queue();

    void add(Client);
    bool isEmpty();
    int size();
    Client removeFirst();

    int maxLength();
    double averageLength();
};

#endif
