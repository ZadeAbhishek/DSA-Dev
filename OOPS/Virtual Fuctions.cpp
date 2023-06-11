#include<bits/stdc++.h>
using namespace std;



class SmartPhone {

    public:
   virtual void TakeASelfie(){
        cout<<"Selfy";
    }

    void MakeCall(){
        cout<<"Selfy";
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

int main(){

    SmartPhone* p = new IOS();
    
    // since Takeselfy fuction is mention virtual in smartphone call ie virtual class
    // it will call most derived function of it

    p->TakeASelfie();
}