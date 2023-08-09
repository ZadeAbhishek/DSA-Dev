#include <iostream>
#include<string>
using namespace std;
// not working
#define my_sizeoff(address) (char *)(&address + 1) - (char *)(&address);

int main()
{
    int x = 8000;

    for(int i = 0 ; i < x ; i++) cout<<i<<" ";
}