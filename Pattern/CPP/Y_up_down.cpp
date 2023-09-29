#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int  N;

    cout<<"Enter N: ";
    cin>>N;
    int ci,cj;
    N =N*2;
    // Run an outer loop from 1 to N*2-1
    for(auto i = 0; i < N-1 ; i++){
        for(auto j = 0 ; j < N+1 ; j++)
        {
             
            if(i == abs(N/2)-1) cout<<"* ";

            else if(j == abs(N/2)) cout<<"* ";
 
            else if(j == 0  && i < N) cout<<"* ";
            
            else if(j == N  && i < N) cout<<"* ";  

            else cout<<"  ";
        }
        cout<<"\n";
    }
    return 0;
}