#include <iostream>
#include <string>
#include <list>

using namespace std;


string checkNumber(int N)
{
    int temp = N;
 
    while (temp > 0) {
        // check for each possible digit
        // if given number consist other than
        // 1, 14, 144 print NO else print YES
        if (temp % 1000 == 144)
            temp /= 1000;
        else if (temp % 100 == 14)
            temp /= 100;
        else if (temp % 10 == 1)
            temp /= 10;
        else {
            return "NO";
        }
    }
 
    return "YES";
}

int main (){
  int x;
  cin>>x;
  string a = checkNumber(x);
  cout<<a;
}