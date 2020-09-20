#include "Queue.hpp"

/**
 * constructor for class Queue
 * @param b an object of type Bank
 */
Queue::Queue(Bank* b) {
    currClients = 0;
    maxClients = 0;
//    lastModifTime = bank->getTime();
    lastModifTime = 0;
    timeClientSum = 0;

    bank = b;
}

Queue::~Queue() = default;

/**
 * add a new cleint to the queue
 * @param c a Client object to be added
 */
void Queue::add(Client c) {
    addToAverage();

    currClients ++;
    if(currClients > maxClients) {
        maxClients = currClients;
    }
    clientList.push_back(c);
}

/**
 * pop the first client from the queue
 * @return a Client object
 */
Client Queue::removeFirst() {
    addToAverage();
    currClients --;
    Client c = clientList.front();
    clientList.pop_front();
    return c;
}

/**
 * check and return a value if the queue is empty or not
 * @return boolean
 */
bool Queue::isEmpty(){
    return clientList.empty();
}

/**
 * calculates and return the current size of the queue
 * @return int
 */
int Queue::size() {
    return clientList.size();
}

/* Function to add (nb of client) * (time passed with his nb of clients) to the curren sum */
void Queue::addToAverage() {
    /*
    double timeDiff = bank->getTime() - lastModifTime;
    timeClientSum += currClients*timeDiff;
    lastModifTime = bank->getTime();
    */
}

/* Returns the max length reached by the queue */
int Queue::maxLength() {
    return maxClients;
}

/* Returns the number of client waiting in average in the queue */
double Queue::averageLength() {
    /*
    addToAverage();
    return timeClientSum / bank->getTime();
    */
}
