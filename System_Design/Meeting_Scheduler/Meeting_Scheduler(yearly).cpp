#include <bits/stdc++.h>

using namespace std;

class Meeting;

class Date;

class DateCoverstion;

typedef unordered_map<Date,vector < Meeting >,DateCoverstion> Calender;




class Date{
  int date;
  int year;
  int month;

public:
   
  bool operator==(const Date &d)const{
      return d.getDate() == this->getDate();
    }
 
  int getDate() const
  {
    return this->date;
  }

  int getYear() const
  {
    return this->year;
  }


  int getMonth() const
  {
    return this->month;
  }
  
  Date(int date,int month,int year){
        this->date = date;
        this->year = year;
        this->month = month; 
    }
};

class DateCoverstion {
    
    public:
    size_t operator()(const Date &d)const{
    return (d.getDate()*10000000 + d.getMonth()*10000 + d.getYear());
    }

    
};

class Room {

  string name;
  Calender calender;

  public:

    Room(string Name) {
      this -> name = Name;
    }

  string getName() {
    return this -> name;
  }

  bool book(Date, int,int);
};

class Meeting {
  int start;
  int end;
  Room room;
  public:
    Meeting(int, int, Room);
  int getStart() {
    return this -> start;
  }

  int getEnd() {
    return this -> end;
  }
};

bool Room::book(Date date,int start, int end) {
  for (Meeting & m: calender[date]) {
    if (m.getStart() < end && start < m.getEnd()) return false;

  }

  Meeting meeting(start, end, * this);
  calender[date].push_back(meeting);
  return true;
}

Meeting::Meeting(int start, int end, Room room): room(room) {
  this -> start = start;
  this -> end = end;
}

class Schedular {

  vector < Room > rooms;

  public:
    Schedular(vector < Room > rooms) {
      this -> rooms = rooms;
    }
  string book(Date, int,int);

};

string Schedular::book(Date date,int start, int end) {
  for (auto & room: rooms) {
    bool flag = room.book(date,start, end);
    if (flag) return room.getName();
  }

  return "No room available";
}

int main() {
  Room room1("Taj");
  Room room2("Oberoi");
  Room room3("Radisson");

  Date date1(14,6,2000);
  Date date2(15,6,2000);

  vector < Room > rooms;
  rooms.push_back(room1);
  rooms.push_back(room2);
  rooms.push_back(room3);

  Schedular schedular(rooms);

  cout << schedular.book(date1,2, 5) << "\n";
  cout << schedular.book(date1,2, 5) << "\n";
  cout << schedular.book(date1,2, 5) << "\n";
  cout << schedular.book(date1,2, 5) << "\n";
  cout << schedular.book(date1,5, 7) << "\n";
  cout << schedular.book(date2,4, 8) << "\n";
  cout << schedular.book(date2,7, 9) << "\n";
  cout << schedular.book(date2,7, 8) << "\n";

  return 0;
}