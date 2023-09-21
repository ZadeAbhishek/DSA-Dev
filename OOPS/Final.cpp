// final Keyword is used Retrict Inhetritance
#include<bits/stdc++.h>
using namespace std;

class parent{
     virtual void show() final{ // now we canot inhertit inside other class this will give error

    }
};

class child:parent{
   void show(){} // see error we cannot inheritance
};


int main(){}