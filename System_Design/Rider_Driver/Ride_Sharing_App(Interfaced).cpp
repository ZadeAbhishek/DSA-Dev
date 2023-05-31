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
	private:
    int id;
    vector<Ride> allRiders;

	public: 
    Rider(int,string);
	void createRide(int, int, int, int);
	void updateRide(int, int, int, int);
	void withdrawRide(int);
	int closeRide(int);


        int getId()
        {
        return this->id;
        }

        void setId(int id)
        {
        this->id = id;
        }
}; 

class System{
    int drivers;
    vector<Rider> riders;

    public:
    System(int,vector<Rider>&);
    void createRide(int,int, int, int, int);
	void updateRide(int,int, int, int, int);
	void withdrawRide(int,int);
	int closeRide(int,int);

};

System::System(int drivers,vector<Rider>& riders){
    
    if(drivers < 2 || riders.size() < 2){
        cout<<"Not enough drivers or Riders\n";
    }
    this->drivers = drivers;
    this->riders = riders;
}

void System :: createRide(int riderId, int rideId, int origin , int dest , int seats){
    if(drivers == 0){
        cout<<"No Drivers around. Can't create ride\n";
        return;
    }
    
    for(Rider &rider: riders){
        if(rider.getId() == riderId){
            rider.createRide(rideId,origin,dest,seats);
            drivers--;
            break;
        }
    }
}

void System :: updateRide(int riderId, int rideId, int origin , int dest , int seats){
    
    for(Rider &rider: riders){
        if(rider.getId() == riderId){
            rider.updateRide(rideId,origin,dest,seats);
            break;
        }
    }
}

void System :: withdrawRide(int riderId, int rideId){
    
    for(Rider &rider: riders){
        if(rider.getId() == riderId){
            rider.withdrawRide(rideId);
            drivers++;
            break;
        }
    }
}
int System :: closeRide(int riderId, int rideId){
    
    for(Rider &rider: riders){
        if(rider.getId() == riderId){
            drivers++;
            return rider.closeRide(rideId);
        }
    }
    return 0;
}




    

Rider::Rider(int id,string Name)
{
	this->id = id;
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
	Rider rider(1,"Abhishek");
	Driver driver("pooja");
    Rider rider2(2,"Yash");
    Rider rider3(3,"Soham");

    vector<Rider> riders;
    riders.push_back(rider);
    riders.push_back(rider2);
    riders.push_back(rider3);

    System system(3,riders);

    rider.createRide(1,50,60,1);
    cout<< rider.closeRide(1)<<endl;
    rider.updateRide(1,50,60,2);
    cout<< rider.closeRide(1)<<endl;

    cout<<"************************************************************"<<endl;

    system.createRide(1,1,50,60,1);
    system.withdrawRide(1,1);
    system.updateRide(1,1,50,60,2);
    cout<< system.closeRide(1,1)<<endl;

    return 0;

}