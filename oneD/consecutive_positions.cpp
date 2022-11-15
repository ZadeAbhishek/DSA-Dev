#include<bits/stdc++.h>
using namespace std;

//int prev[3] = {0,0,0};

 bool check(vector<int> x)
 {
    int prev = x[0];

    for(auto i = 1 ; i < size(x) ; i++){
           if(x[i] != prev)
           {
            prev = x[i];  
            continue;
           }
           else return false;
    }
    return true;
 }

int consec(vector<int> &balls, vector<int> &temp,int count, vector<int> &flag,int prev)
{
    
    if(size(temp) == size(balls))
    {
        
        if(check(temp)) count++;
        return count;
    }

       for(auto i = 0; i < balls.size() ; i++){
        
        if(!flag[i]){
        flag[i] = 1;    
        temp.push_back(balls[i]);
        count = consec(balls,temp,count,flag,balls[i]);
        temp.pop_back();
        flag[i] = 0;
        }

       }

       // flag[balls[i]] = 0;
        
    return count;
}

int main (){

    int red = 1;
    int green = 1;
    int yellow = 1;
    vector<int> balls = {1,2,2,3};
    vector<int> temp;
    vector<int> flag(balls.size(),0);
    cout<<consec(balls,temp,0,flag,0);
    // using DP
}