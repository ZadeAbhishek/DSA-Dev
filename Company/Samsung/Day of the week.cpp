/*

Write a function that calculates the day of the week for any particular date in the past or future. 
A typical application is to calculate the day of the week on which someone was born or some other 
special event occurred.


Understanding the Maths:

14/09/1998
dd=14
mm=09
yyyy=1998 //non-leap year

Step 1: Information to be remembered.
 Magic Number Month array.
 For Year: {0,3,3,6,1,4,6,2,5,0,3,5}
 DAY array starting from 0-6: {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}
 Century Year Value: 1600-1699 = 6
      1700-1799 = 4
      1800-1899 = 2
      1900-1999 = 0
      2000-2099 = 6..

Step 2: Calculations as per the steps
 
 Last 2 digits of the year:  98
 Divide the above by 4:     24
 Take the date(dd):      14
 Take month value from array: 5 (for September month number 9)
 Take century year value:  0  ( 1998 is in the range 1900-1999 thus 0)
          -----
 Sum:        141
 
 Divide the Sum by 7 and get the remainder: 141 % 7 = 1
 
 Check the Day array starting from index 0: Day[1] = Monday

**If leap year it will be the remainder-1

*/

#include<iostream>
using namespace std;

int day_of_week(int d, int m, int y){

    // i dont understant logic behind it
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    y -= m < 3;

    int day = (y+y/4 + y/400 - y/100 + t[m-1] + d)%7;

    return day;
}

int main(){

    int d,m,y;
    cin>>d>>m>>y;
    const string str[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int day = day_of_week(d,m,y);
    cout<<str[day]<<"\n";
    return 0;
}
