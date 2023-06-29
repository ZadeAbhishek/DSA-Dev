/*
Elevator System Design

components
1.Elevator
 1.1 Capacity
   1.1.1 Max and Min capcity 
 
 1.2 Direction
   1.2.1 UP , DOWN
 
 1.3 Current Floor

2.System

2.1 Start Elevator
  2.1.1 init Elevator

2.2 Get User Request
  2.2.1 First Requestion will set Direction
  2.2.2 Check User requestion is valid
  2.2.3 set Elevator  

*/

class Elevator{
    private:
    enum Direction{UP,DOWN};
    int maxCapacity;
    int currCapacity = 0; // No Passenger 
    int currFloor = 0; // Ground Floor
    Direction direction;
    
    public:
    Elevator(int);


};

Elevator::Elevator(int max_capacity){
    this->maxCapacity = max_capacity;
}

class System{
    Elevator elevator;

    public:
    System(int)
};
