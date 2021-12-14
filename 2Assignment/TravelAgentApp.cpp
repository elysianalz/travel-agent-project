/*
 * TravelAgent.cpp
 *
 *      Author: dongmo
 */

#ifndef TRAVELAGENT_CPP_
#define TRAVELAGENT_CPP_

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

#include "Constants.h"
#include "ClientRequest.h"
#include "Ticket.h"
#include "FlightTicket.h"
#include "EventTicket.h"
#include "HotelVoucher.h"
#include "Package.h"
#include "TravelAgent.h"

void classTest1() {
	cout << "Test ClientRequest class ... " << endl;
// two examples of client requests
	ClientRequest requestList[MAXREQUESTS];
	requestList->processRequests(requestList);
	
	cout << "* Test data ..." << endl;
	cout << setw(8) << "Client No" << setw(8) << "budget" << setw(8) << "hotel"
			<< setw(8) << "events" << endl;

	for (int i = 0; i < 2; i++)
		requestList[i].print();

	cout << "\n* Test functions (an example)..." << endl;
	cout << "  - Earliest event day: " << requestList[0].earliestEventDay()
			<< endl;
	cout << "  - Latest event day: " << requestList[0].latestEventDay() << endl;
}

void classTest2() {
	cout << "Test FlightTicket class ... " << endl;
	// two examples of flight tickets
	FlightTicket *tickets[2];
	tickets[0] = new FlightTicket(0, 1);
	tickets[1] = new FlightTicket(1, 7);

	for (int i = 0; i < 2; i++)
		tickets[i]->printTicket();

}

void classTest3()
{
	HotelVoucher* vouchers[2];
	vouchers[0] = new HotelVoucher(1, 3);
	vouchers[1] = new HotelVoucher(2, 3);

	for (int i = 0; i < 2; i++)
	{
		vouchers[i]->printTicket();
	}
}

void classTest4()
{
	EventTicket* tickets[2];
	tickets[0] = new EventTicket(11);
	tickets[1] = new EventTicket(9);

	for (int i = 0; i < 2; i++)
	{
		tickets[i]->printTicket();
	}
}

void classTest5()
{

}

void classTest6()
{
	FlightTicket* tickets[2];
	tickets[0] = new FlightTicket(0, 1);
	tickets[1] = new FlightTicket(1, 7);

	HotelVoucher* vouchers[2];
	vouchers[0] = new HotelVoucher(1, 3);
	vouchers[1] = new HotelVoucher(2, 3);

	EventTicket* events[2];
	events[0] = new EventTicket(11);
	events[1] = new EventTicket(9);

	Package* package = new Package(tickets, vouchers, events);
	package->flights[0]->printTicket();
	package->flights[1]->printTicket();
	package->vouchers[0]->printTicket();
	package->vouchers[1]->printTicket();
	package->events[0]->printTicket();
	package->events[1]->printTicket();
}

void travelAgentClass()
{
	ClientRequest requestList[MAXREQUESTS];
	requestList->processRequests(requestList);

	TravelAgent agent = TravelAgent(requestList, requestList->numberOfRequests);
	agent.processRequest();
}

int main() {
	srand(time(0)); // seed random number generator

	cout << "Choose a class to test: " << endl;
	cout << "1. Test ClientRequest class" << endl;
	cout << "2. Test FlightTicket class" << endl;
	cout << "3. Test HotelVoucher class" << endl;
	cout << "4. Test EventTicket class" << endl;
	cout << "5. Test RequestGenerator class" << endl;
	cout << "6. Test Package class" << endl;
	cout << "7. Run TravelAgent class" << endl;
	cout << "8. Run Smart Travel agent" << endl;
	cout << "9. Quit" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		classTest1();
		break;
	case 2:
		classTest2();
		break;
	case 3:
		classTest3();
		break;
	case 4:
		classTest4();
		break;
	case 5:
		// randomly regenerate 100 to 150 client requests and writing in a text file
		cout << "To be implemented!" << endl;
		break;
	case 6:
		classTest6();
		break;
	case 7:
		travelAgentClass();
		break;
	case 8:
		//Run your smart travel agent display the generated packages, your profit and remaining resources.
		cout << "To be implemented!" << endl;
		break;
	case 9:
		cout << "Bye!" << endl;
		break;
	default:
		cout << "Invalid input!" << endl;
	}

	return 0;

}

#endif /* TRAVELAGENT_CPP */
