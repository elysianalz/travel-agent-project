#ifndef HOTELVOUCHER_H_
#define HOTELVOUCHER_H_

#include "Ticket.h"
class HotelVoucher : public Ticket
{
private:
    int type;
public:
    HotelVoucher(int day, int type) : Ticket(day, 0)
    {
        this->day = day;
        this->type = type - 3;
        this->fullPrice = hotelPriceMap[this->type];
    }

    ~HotelVoucher()
    {

    }

    void printTicket() {
        cout << "hotel voucher:  day:" << day << " cost: " << fullPrice << " type: " << type + 3 << " star" << endl;
    }
};

#endif // !HOTELVOUCHER_H_



