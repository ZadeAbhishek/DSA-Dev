// C++ program to demonstrate deletion of child class using
// base pointer using Virtual Destructor.
 
#include <iostream>

using namespace std;

class Base {
    public: Base() {
        cout << "Constructor of Base class is called" << endl;
    }
    // Defining virtual destructor.
    virtual~Base() {
        // At last, it will be printed.
        cout << "Destructor of Base class is called" << endl;
    }
};

// Inheriting features of Base class in Child class.
class Child: public Base {
    public: Child() {
            cout << "Constructor of Child class is called" << endl;
        }
        // It will be called before calling the Base class destructor.
        ~Child() {
            cout << "Destructor of Child class is called" << endl;
        }
};

int main() {
    Base * b = new Child; //  Object refers to the Base class.
    delete b; // Deleting the pointer object.
    return 0;
}

/*
if virtaul destructor is not used
Constructor of Base class is called
Constructor of Child class is called
Destructor of Base class is called


if used 
Constructor of Base class is called
Constructor of Child class is called
Destructor of Child class is called
Destructor of Base class is called

*/