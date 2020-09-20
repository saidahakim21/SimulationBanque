#include "Queue.hpp"

/* Constructor with the index in the array of waiting lists in Bank */
Queue::Queue(Bank* b) {
    currClients = 0;
    maxClients = 0;
//    lastModifTime = bank->getTime();
    lastModifTime = 0;
    timeClientSum = 0;

    bank = b;
}

Queue::~Queue() = default;

/* Add Client to Queue */
void Queue::add(Client c) {
    addToAverage();

    currClients ++;
    if(currClients > maxClients) {
        maxClients = currClients;
    }
    clientList.push_back(c);
}

/* Remove the first waiting Client of the queue and returns it */
Client Queue::removeFirst() {
    addToAverage();
    currClients --;
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

/* Returns the index of the queue in the Bank */
int Queue::getNumber()
{
    return number;
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
