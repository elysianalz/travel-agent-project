#ifndef TRAVELAGENT_H_
#define TRAVELAGENT_H_

using namespace std;

class TravelAgent {
private:
	ClientRequest *requestList;
	int firstDay;
	int lastDay;
	int stay;
	int numEvents;
	int costs = 0;
	int numberOfRequests;
	FlightTicket* flights[2];
	HotelVoucher* vouchers[NUMBEROFDAYS];
	EventTicket* events[NUMBEROFEVENTS];
public:
	TravelAgent(ClientRequest *requestList, int numberOfRequests)
	{
		this->requestList = requestList;
		this->numberOfRequests = numberOfRequests;
	}

	~TravelAgent()
	{

	}

	void processRequest()
	{
		ofstream fout;
		fout.open("rejected.txt");
		for (int i = 0; i < this->numberOfRequests; i++)
		{
			this->firstDay = requestList[i].earliestEventDay();
			this->lastDay = requestList[i].latestEventDay();
			this->bookFlights();
			this->bookHotels(i);
			this->bookEvents(i);
			this->calcStay();
			Package package = this->createPackage(i);
			package.costs = this->costs;
			package.budget = requestList[i].budget;

			if (requestList[i].budget - this->costs >= 0)
			{
				package.printPackage();
			}
			else {
				package.valid = false;
				fout << "id: " << requestList[i].cId 
					<< " budget: " << requestList[i].budget 
					<< " costs: " << this->costs << endl;
			}

			costs = 0;
		}
		fout.close();
	}

	void calcStay()
	{
		this->stay = this->lastDay - this->firstDay;
	}

	void bookFlights()
	{
		flights[0] = new FlightTicket(0, this->firstDay);
		flights[1] = new FlightTicket(1, this->lastDay);
		this->costs += flights[0]->getTicketPrice();
		this->costs += flights[1]->getTicketPrice();
	}

	void bookHotels(int k)
	{
		int count = 0;
		for (int i = firstDay; i < lastDay; i++)
		{
			vouchers[count] = new HotelVoucher(i, requestList[k].hotelType);
			this->costs += hotelPriceMap[requestList[k].hotelType - 3];
			count++;
		}
	}

	void bookEvents(int k)
	{
		int j = 0;
		for (int i = 0; i < NUMBEROFEVENTS; i++)
		{
			if (requestList[k].events[i] == true)
			{
				events[j] = new EventTicket(i);
				this->costs += eventPriceMap[i];
				j++;
			}
		}
		this->numEvents = j;
	}

	Package createPackage(int i)
	{
		Package package = Package(this->flights, this->vouchers, this->events);
		package.stay = this->stay;
		package.numEvents = this->numEvents;
		package.cId = requestList[i].cId;
		return package;
	}
};
#endif // TRAVELAGENT_H_



