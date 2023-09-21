/*
Elevator System
1. Elevator
  1.1 Direction
  1.2 CurrFloor
  1.3 MaxCapacity
2. System
  2.1 Start Elevator
  2.2 Validate User Request
  2.3 CheckValid Floor
  2.3 CheckValid Direction
  2.4 Check Capcity 
*/

#include<bits/stdc++.h>
using namespace std;


class Elevator;
class System;

enum Direction{UP,DOWN};

class Elevator{
  private:
  Direction direction;
  int currFloor = 0;
  int maxCapacity = 0; // accept through Constructor
  int currCapcity = 0;
  int maxFloor = 0;
  int minFloor = 0;

  public:
  Elevator(int,int,int);
  int getCurrFloor();
  void SetFloor(int);
  int getCapacity();
  void setCapacity(int);
  int getMaxCapcity();
  Direction getDirection();
  void setDirection(Direction);
  int getMaxFloor();
  int getMinFloor();
};

Elevator::Elevator(int C, int maxf , int minf){
  this->maxCapacity = C;
  this->maxFloor = maxf;
  this->minFloor = minf;
}
int Elevator::getCurrFloor(){
    return this->currFloor;
}
void Elevator::SetFloor(int f){
  this->currFloor = f;
}
Direction Elevator::getDirection(){
  return this->direction;
}
void Elevator::setDirection(Direction d){
  this->direction = d;
}

int Elevator::getCapacity(){
  return this->currCapcity;
}

int Elevator::getMaxCapcity(){
  return this->maxCapacity;
}

void Elevator::setCapacity(int c){
  this->currCapcity = c;
}

int Elevator::getMaxFloor(){
  return this->maxFloor;
}

int Elevator::getMinFloor(){
  return this->minFloor;
}

class System{
  private:
  Elevator *elevator = new Elevator(5,3,0); //Current capacity is 5

  public:
  bool checkCapacity(int);
  bool checkDirection(Direction);
  bool checkFloor(int);
  bool validUserRequest(int,int,int);
  void startElevator();
};

bool System::checkCapacity(int c){
   int curr = elevator->getCapacity();
   int max = elevator->getMaxCapcity();
   if(c >= (max - curr)) return false;
   return true;
}

bool System::checkDirection(Direction d){
   if(elevator->getDirection() == d) return true;
   return false;
}

bool System::checkFloor(int floor){
   int max = elevator->getMaxFloor();
   int min = elevator->getMinFloor();
   if(floor >= min && floor <= max) return true;
   return false;
}

bool System::validUserRequest(int capacity,int s, int floor){
   Direction d = s == 1?Direction::UP:Direction::DOWN;
   if(this->checkCapacity(capacity) && this->checkDirection(d) && this->checkFloor(floor)) return true;
   else return false;
}

void System::startElevator(){
  string run = "Start";
  string FeedBack = "";
  int floor = 0;
  int direction = 0;
  int capacity = 0;
  while(run != "stop"){
     cout<<"Enter Floor capacity Direction(0/1)";
     cin>>floor>>capacity>>direction;
     if(this->elevator->getCurrFloor() == 0){
         if(this->checkFloor(floor) && this->checkCapacity(capacity)) this->elevator->setCapacity(capacity),this->elevator->SetFloor(floor) ,FeedBack = "";
         else FeedBack = "Bad Request";
     }
     else{
     if(this->validUserRequest(capacity,direction,floor)){
       int currCapacity = this->elevator->getCapacity();
       currCapacity += capacity;
       this->elevator->setCapacity(currCapacity);
       this->elevator->SetFloor(floor);
       this->elevator->setDirection(direction==1?Direction::UP:Direction::DOWN);
     }
     else FeedBack = "Bad Request";
     }
     if(FeedBack != "") cout<<FeedBack<<"\n";
     else cout<<"Elevator Details"<<"\n"<<"Floor:"<<floor<<" "<<"Capacity:"<<capacity<<" "<<"Direction:"<<direction<<"\n";
     
     cout<<"To exit Type stop To continue Type Anything"<<"\n";
     cin>>run;
  }
  return;
}


int main(){
  System *system = new System();
  system->startElevator();
  return 0;
}
