/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#include "Queue.hpp"

Queue::Queue() {
    nbClients = 0;
    currentClientsNb = 0;
    lastModifTime = 0;
    timeClientSum = 0;

    bank = nullptr;
}

/* Constructor with the index in the array of waiting lists in Bank */
Queue::Queue(Bank* bank)
{
    nbClients = 0;
    currentClientsNb = 0;
    lastModifTime = 0;
    timeClientSum = 0;

    bank = bank;
}


/* Add Client to Queue */
void Queue::add(Client c) {
    //addToAverage(); Todo

    nbClients ++;
    if(nbClients > currentClientsNb) {
        currentClientsNb = nbClients;
    }
    clientList.push_back(c);
}

/* Remove the first waiting Client of the queue and returns it */
Client Queue::removeFirst() {
    //addToAverage(); Todo

    nbClients --;
    Client c = clientList.front();
    clientList.pop_front();
    return c;
}

/* Returns if the queue is empty */
bool Queue::isEmpty(){
    return clientList.empty();
}

/* Returns the size of the queue */
int Queue::size() {
    return clientList.size();
}

/* Function to add (nb of client) * (time passed with his nb of clients) to the curren sum */
void Queue::addToAverage(double time) {
    double timeDiff = time - lastModifTime;
    timeClientSum += nbClients * timeDiff;
    lastModifTime = time;
}

/* Returns the max length reached by the queue */
int Queue::getCurrentClientsNb() {
    return currentClientsNb;
}

/* Returns the number of client waiting in average in the queue */
double Queue::averageLength(double time) {
    addToAverage(time);
    return timeClientSum / time;
}
