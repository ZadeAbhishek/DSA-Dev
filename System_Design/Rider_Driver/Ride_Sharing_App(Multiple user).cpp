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
	private: vector<Ride> allRiders;

	public: Rider(string);
	void createRide(int, int, int, int);
	void updateRide(int, int, int, int);
	void withdrawRide(int);
	int closeRide(int);

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
    Ride currRide;
	currRide.setId(id);
	currRide.setOrigin(origin);
	currRide.setDestination(dest);
	currRide.setSeats(seats);
	currRide.setRideStatus(RideStatus::CREATED);
    allRiders.push_back(currRide);

}

void Rider::updateRide(int id, int origin, int dest, int seats)
{
	auto iter = allRiders.rbegin();
    for(; iter != allRiders.rend(); ++iter){
        if(iter->getId() == id){
            break;
        }
    }
    
    if(iter->getRideStatus() != RideStatus::CREATED){
        cout<<"Ride wasn't in Progress \n";
        return;
    }

    iter->setOrigin(origin);
    iter->setDestination(dest);
    iter->setSeats(seats);

}

void Rider::withdrawRide(int id)
{
	auto iter = allRiders.rbegin();
    for(; iter != allRiders.rend(); ++iter){
        if(iter->getId() == id){
            break;
        }
    }
     if(iter->getRideStatus() != RideStatus::CREATED){
        cout<<"Ride wasn't in Progress. Can't Withdraw\n";
        return;
    }

    iter->setRideStatus(RideStatus::WITHDRAWN);
    allRiders.erase((iter+1).base());
}

int Rider::closeRide(int id)
{
	auto iter = allRiders.rbegin();
    for(; iter != allRiders.rend(); ++iter){
        if(iter->getId() == id){
            break;
        }
    }
    
    if(iter->getRideStatus() != RideStatus::CREATED){
        cout<<"Ride wasn't in Progress, Can't Close\n";
        return 0; 
    }

    iter->setRideStatus(RideStatus::COMPLETED);
    return iter->calculationFar(allRiders.size() >= 10);

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
	cout << rider.closeRide(1) << endl;
    rider.createRide(2, 20, 100, 1);
	rider.updateRide(1, 50, 60, 2);
    cout<< rider.closeRide(2)<<endl;
    rider.updateRide(2, 50, 60, 2);
	cout << rider.closeRide(1) << endl;
}