#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    // Run an outer loop from 1 to N*2-1
    while(1){

    if(i == 10) i = 0;  

    int  N = arr[i];    
    //cout<<"Enter N: ";
    //cin>>N;
    N =N*2;
    for(auto i = 0; i < N-1 ; i++){
        for(auto j = 0 ; j < N+1 ; j++)
        {
             
            if(i == abs(N/2)-1) cout<<"ab ";

            else if(j == abs(N/2)) cout<<"ab ";
 
            else if(j == 0  && i < N) cout<<"ab ";
            
            else if(j == N  && i < N) cout<<"ab ";  

            else cout<<"  ";
        }
        cout<<"\n";
    }
   i++;
    }
    return 0;
}