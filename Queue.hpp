#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP

#include <iostream>
#include <deque>

#include "Bank.hpp"
#include "Client.hpp"

class Queue
{
    int nbClients;
        int currentClientsNb;
        double lastModifTime;
        double timeClientSum;
        Bank* bank;

        std::deque<Client> clientList;

        void addToAverage();

    public:
        Queue();
        Queue(Bank *bank);
        ~Queue();

        void add(Client);
        bool isEmpty();
        int size();
        Client removeFirst();

        int getCurrentClientsNb();
        double averageLength();
};

#endif
