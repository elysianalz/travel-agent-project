#include "Ticket.h"
class EventTicket : public Ticket
{
private:
    int eventNo;
    string eventName;
public:

    EventTicket(int eventNo) : Ticket(0, 0)
    {
        this->eventNo = eventNo;
        this->fullPrice = eventPriceMap[this->eventNo];
        this->day = eventDayMap[this->eventNo];
        this->eventName = nameMap[eventNo];
    }

    ~EventTicket()
    {

    }

    void printTicket()
    {
        cout << "Event: " 
            << " no." << this->eventNo 
            << " name: " << this->eventName 
            << " day: " << this->day 
            << " price: $" << this->fullPrice << endl;
    }

    string getEventName()
    {
        return this->eventName;
    }
};

