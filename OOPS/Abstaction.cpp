#include<bits/stdc++.h>
using namespace std;


class SmartPhone {

    public:
    virtual void TakeASelfie()=0; // pure virtual fuction
    virtual void MakeCall()=0;
};


class Andriod : public SmartPhone {

    public:
    void TakeASelfie(){
        cout<<"Andriod Selfy";
    }

    void MakeCall(){
        cout<<"Andriod Selfy";
    }
}; 


class IOS : public SmartPhone {

    public:
    void TakeASelfie(){
        cout<<"IOS Selfy";
    }

    void MakeCall(){
        cout<<"IOS Selfy";
    }
}; 