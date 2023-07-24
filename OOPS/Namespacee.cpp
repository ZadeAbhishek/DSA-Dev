#include<iostream>

namespace a{
    int age = 10;
}

namespace b{
    int age = 20;
}

using namespace a;
using namespace b;

int main(){

    std::cout<<a::age<<"\n";
}