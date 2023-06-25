#include<iostream>

#define LOG(x) std::cout << x << std::endl;

int main(){
    int var = 8;
    void* ptr1 = &var;
    int* ptr2 = &var;
    LOG(var);
    *ptr2 = 10;
    LOG(var);
    void* ptr = nullptr;  // ptr is of typr void
    std::cin.get();
}