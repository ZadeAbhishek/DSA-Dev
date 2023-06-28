#include <bits/stdc++.h>

using namespace std;

class Meeting;

typedef vector < Meeting > Calender;

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

   bool book(int, int);
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

bool Room::book(int start, int end) {
   for (Meeting & m: calender) {
      if (m.getStart() < end && start < m.getEnd()) return false;

   }

   Meeting meeting(start, end, * this);
   calender.push_back(meeting);
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
   string book(int, int);

};

string Schedular::book(int start, int end) {
   for (auto & room: rooms) {
      bool flag = room.book(start, end);
      if (flag) return room.getName();
   }

   return "No room available";
}

int main() {
   Room room1("Taj");
   Room room2("Oberoi");
   Room room3("Radisson");

   vector < Room > rooms;
   rooms.push_back(room1);
   rooms.push_back(room2);
   rooms.push_back(room3);

   Schedular schedular(rooms);

   cout << schedular.book(2, 5) << "\n";
   cout << schedular.book(5, 8) << "\n";
   cout << schedular.book(4, 8) << "\n";
   cout << schedular.book(3, 6) << "\n";
   cout << schedular.book(7, 8) << "\n";

   return 0;
}