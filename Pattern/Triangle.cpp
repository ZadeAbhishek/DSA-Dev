#include<bits/stdc++.h>
using namespace std;

void printTriangle(int n) {

        for (int i=1; i<=n; i++) {

            for (int j=1; j<=i+n-1; j++) {

                if (n-i < j)

                  cout << "*";

                else 

                  cout << "^";

            }

            cout << endl;
            
        }

    }

 int main(){

   int s;
   cin>>s;
   printTriangle(s);
   return 0;
 }   