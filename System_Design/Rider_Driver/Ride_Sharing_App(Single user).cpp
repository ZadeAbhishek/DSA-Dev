#include <bits/stdc++.h>
using namespace std;

enum RideStatus
{
	IDLE, CREATED, WITHDRAWN, COMPLETED
};

class Ride
{
	static
	const int AMT_PER_KM = 20;
	int id;
	int origin;
	int destination;

	int seats;
	RideStatus rideStatus;

	public:
		int calculationFar(bool);
	Ride();
	int getOrigin()
	{
		return this->origin;
	}

	void setOrigin(int origin)
	{
		this->origin = origin;
	}

	int getDestination()
	{
		return this->destination;
	}

	void setDestination(int destination)
	{
		this->destination = destination;
	}

	int getId()
	{
		return this->id;
	}

	void setId(int id)
	{
		this->id = id;
	}

	int getSeats()
	{
		return this->seats;
	}

	void setSeats(int seats)
	{
		this->seats = seats;
	}

	RideStatus getRideStatus()
	{
		return this->rideStatus;
	}

	void setRideStatus(RideStatus rideStatus)
	{
		this->rideStatus = rideStatus;
	}
};

class Person
{
	public:
		string name;
};

class Driver: private Person
{
	public: Driver(string);
};

class Rider: private Person
{
	private: vector<Ride> completeRiders;
	Ride currRide;

	public: Rider(string);
	void createRide(int, int, int, int);
	void updateRide(int, int, int, int);
	void withdrawRide(int);
	int closeRide();

};

Rider::Rider(string Name)
{
	this->name = Name;
}

void Rider::createRide(int id, int origin, int dest, int seats)
{
	if (origin >= dest)
	{
		cout << "Wrong Values Cannot Provide Ride\n";
		return;
	}

	currRide.setId(id);
	currRide.setOrigin(origin);
	currRide.setDestination(dest);
	currRide.setSeats(seats);
	currRide.setRideStatus(RideStatus::CREATED);

}

void Rider::updateRide(int id, int origin, int dest, int seats)
{
	if (currRide.getRideStatus() == RideStatus::WITHDRAWN)
	{
		cout << "Cannot Update Ride Since WithDrawn\n";
		return;
	}

	if (currRide.getRideStatus() == RideStatus::COMPLETED)
	{
		cout << "Cannot Update Ride Since Completed\n";
		return;
	}

	createRide(id, origin, dest, seats);

}

void Rider::withdrawRide(int id)
{
	if (currRide.getId() != id)
	{
		cout << "Wrong Id cannot WithDrawn\n";
		return;
	}

	if (currRide.getRideStatus() != RideStatus::CREATED)
	{
		cout << "Ride wasnit in progress. Can't Wothdrawn\n";
		return;
	}

	if (currRide.getRideStatus() == RideStatus::COMPLETED)
	{
		cout << "Cannot WithDrawn Ride Since it is Completed\n";
		return;
	}

	currRide.setRideStatus(RideStatus::WITHDRAWN);

}

int Rider::closeRide()
{
	if (currRide.getRideStatus() != RideStatus::CREATED)
	{
		cout << "Ride wasnit in progress. Can't Withdrawn\n";
		return 0;
	}

	currRide.setRideStatus(RideStatus::COMPLETED);
	completeRiders.push_back(currRide);
	return currRide.calculationFar(completeRiders.size() >= 10);
}

Driver::Driver(string name)
{
	this->name = name;
}

Ride::Ride()
{
	// constructor
	id = origin = destination = seats = 0;
	rideStatus = RideStatus::IDLE;
}

int Ride::calculationFar(bool isPriorityRider)
{
	int dist = destination - origin;
	if (seats < 2)
	{
		return dist *AMT_PER_KM *(isPriorityRider ? 0.75 : 1);
	}

	return dist *seats *AMT_PER_KM *(isPriorityRider ? 0.5 : 0.75);
}

int main()
{
	Rider rider("Abhishek");
	Driver driver("pooja");

	rider.createRide(1, 50, 60, 1);
	cout << rider.closeRide() << endl;
	rider.updateRide(1, 50, 60, 2);
	cout << rider.closeRide() << endl;
}