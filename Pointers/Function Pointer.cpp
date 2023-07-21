#include<bits/stdc++.h>
using namespace std;


int multipy(int x , int y) {return x * y;};


int main(){

    // fuction pointer declaration
    int (*multipy_function_pointer)(int, int);

    // pointing to functio variable
    multipy_function_pointer = multipy;

    
    // here varaible data type is same as retur type of fuction 
    int result = multipy_function_pointer(2,3);

    cout<<result<<"\n";
}