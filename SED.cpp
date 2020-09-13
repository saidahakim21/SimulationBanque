
#include "SED.hpp"

SED::SED(double start)
{
    time = start;
}

SED::~SED()
{
    delete eventsList;
}

void SED::start() {
}

void SED::addEvent(Event* e)
{
    struct eventElement *temp = (struct eventElement*) malloc(sizeof(struct eventElement));
    temp->event = e;
    
    struct eventElement *temp2 = eventsList;
    struct eventElement **temp3 = &eventsList;

    while(temp2 != NULL && temp2->event->time() < temp->event->time())
    {
        temp3 = &temp2->next;
        temp2 = temp2->next;
    }
    *temp3 = temp;
    temp->next = temp2;
}

double SED::getTime() {
    return time;
}
