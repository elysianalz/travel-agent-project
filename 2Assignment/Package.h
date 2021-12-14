#ifndef PACKAGE_H_
#define PACKAGE_H_
class Package
{
public:
	int stay;
	int numEvents;
	int cId;
	int costs = 0;
	int budget;
	bool valid = true;
	FlightTicket** flights;
	HotelVoucher** vouchers;
	EventTicket** events;
	
	Package(FlightTicket* flights[], HotelVoucher* vouchers[NUMBEROFDAYS], EventTicket* events[])
	{
		this->flights = flights;
		this->vouchers = vouchers;
		this->events = events;
	}

	~Package()
	{
		
	}

	void printFlights()
	{
		flights[0]->printTicket();
		flights[1]->printTicket();
	}

	void printVouchers()
	{
		for (int i = 0; i < stay; i++)
		{
			vouchers[i]->printTicket();
		}
	}

	void printEvents()
	{
		for (int i = 0; i < this->numEvents; i++)
		{
			events[i]->printTicket();
		}

	}

	void printCostSummary()
	{
		cout << "budget: " << this->budget << " costs: " << this->costs << endl;
	}

	void printPackage()
	{
		cout << "package for request: " << this->cId << endl;
		printFlights();
		printVouchers();
		printEvents();
		printCostSummary();
		cout << endl;
	}
};
#endif // !PACKAGE_H_



