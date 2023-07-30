#include<iostream>
// not working
#define my_sizeoff(address) (char*)(&address+1) - (char*)(&address);

int main(){
    int x = 10;
    std::cout<<my_sizeoff(x);
}