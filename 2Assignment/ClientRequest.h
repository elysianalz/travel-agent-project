/*
 * ClientRequest.h
 *      Author: dongmo
 */

#ifndef CLIENTREQUEST_H_
#define CLIENTREQUEST_H_

class ClientRequest {
public:
	int cId;
	int hotelType;
	bool events[NUMBEROFEVENTS];
	int budget;
	int numberOfRequests = 0;

	ClientRequest() {
		cId = -1;
		hotelType = -1;
		budget = -1;
		for (int i = 0; i < NUMBEROFEVENTS; i++)
			events[i] = false;
	}

	int earliestEventDay() {
		int flyin = 9;
		for (int i = 0; i < NUMBEROFEVENTS; i++) {
			if (events[i] && eventDayMap[i] < flyin)
				flyin = eventDayMap[i];
		}
		return flyin;
	}

	int latestEventDay() {
// ADD YOUR CODE HERE!
		int flyout = 0;
		for (int i = 0; i < NUMBEROFEVENTS; i++)
		{
			if (events[i] && eventDayMap[i] > flyout)
			{
				flyout = eventDayMap[i];
			}
		}
		return flyout;
	}

	void print() {
		cout << setw(8) << cId << ":" << setw(8) << budget << setw(8)
				<< hotelType << setw(8);

		for (int i = 0; i < NUMBEROFEVENTS; i++) {
			if (events[i]) {
				cout << i;
				if (i < NUMBEROFEVENTS - 1)
					cout << ",";
			}
		}

		cout << endl;
	}

	void processRequests(ClientRequest requestList[])
	{
		int reqNum = 0;

		ifstream fin;
		fin.open("requestlist.txt");
		string request;

		while (!fin.eof())
		{
			fin >> request;
			// split values
			string budget = request.substr(0, request.find(","));
			string hotelType = request.substr(request.find(",") + 1, 1);
			string events = request.substr(request.find("["), request.find("]"));
			events = events.substr(1);
			events = events.substr(0, events.find("]"));

			// split events  and process
			string delimiter = ",";
			size_t pos = 0;
			string token;
			int num;
			while ((pos = events.find(delimiter)) != string::npos) {
				token = events.substr(0, pos);
				num = stoi(token);
				requestList[reqNum].events[num] = true;
				events.erase(0, pos + delimiter.length());
			}
			requestList[reqNum].events[stoi(events)] = true;
			requestList[reqNum].budget = stoi(budget);
			requestList[reqNum].hotelType = stoi(hotelType);
			requestList[reqNum].cId = reqNum;
			reqNum++;
			numberOfRequests++;
		}
		fin.close();
	}
};

#endif /* CLIENTREQUEST_H_ */
