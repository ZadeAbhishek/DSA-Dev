/* Implement N stack using single Array */
#include<iostream>
#include<string.h> // string also has implementation of memeset
using namespace std;

class Nstack{
    private:
    int *arr;
    int *top;
    int *next;
    int freeSpot;
    int n,s; // array size stack size
    public:
    Nstack(int , int);
    bool push(int,int);
    int pop(int);
};

// constrcutor
Nstack::Nstack(int N, int S){
     n = N;
     s = S;
     arr = new int[n];
     memset(arr,0,n);

     top = new int[s];
     memset(top,-1,s);

     next = new int[n];
     
     for(int i = 0 ; i < n ; i++){
        next[i] = i+1;
     }
     // last element do not have next element
     next[n] = -1;

     freeSpot = 0;
}

bool Nstack::push(int no, int StackNo){

    
    int index;

    // step 1 get freespot
    index = freeSpot;

    // update freeSpot
    freeSpot = next[index];

    //update element in stack
    arr[index] = no;

    //update next with current pos
    next[index] = top[StackNo-1];

    // update top 
    top[StackNo-1] = index;

    return true;
}


int Nstack::pop(int pos){

    // edges case
    if(top[pos-1] == -1) return -1;

    int index;

    // get current index
    index = top[pos-1];

    //update pos
    top[pos-1] = next[index];

    //update next
    next[index] = freeSpot;

    //update freespot
    freeSpot = index;

    return arr[index];
}

int main(){

    Nstack *stack = new Nstack(9,3);
    stack->push(1,1);
    stack->push(2,2);
    stack->push(3,3);
    stack->push(2,1);
    cout<<stack->pop(1)<<"\n";
    cout<<stack->pop(1)<<"\n";
}