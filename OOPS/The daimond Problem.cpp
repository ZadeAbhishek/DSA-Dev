#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void print(string s){
        cout<<"Class A"<<" "<<s<<endl;
    }
};


class B: virtual public A{
    public:
   void print(string s){
        cout<<"Class B"<<" "<<s<<endl;
    }
};

class C: virtual public A{
    public:
   void print(string s){
        cout<<"Class C"<<" "<<s<<endl;
    }
};

class D: virtual public B, public C{
};

int main ()
{
    cout<<"The Diamond Problem"<<endl;
    D *temp  = new D();
    temp->A::print("Test");
}


// To solve this ambiguity scope resolution operator is used denoted by ‘ :: ‘

// Syntax:

// ObjectName.ClassName::FunctionName();