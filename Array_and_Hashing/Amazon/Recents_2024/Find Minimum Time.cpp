// This is the approch by Chatgpt
#include<bits/stdc++.h>
using namespace std;
int findMinimunTime(int n, int k, vector<int>& position){
   sort(position.begin(),position.end()); // I am doing sorting in case if not sort sice we are delling with number line question
   int minT = INT_MAX;
   for(int i = 0 ; i <= n - k ; i++){
    // int leftNumber = position[i];
    // int rightNumber = position[i + k - 1]; // This is all number
    int getDistanceOfLine = position[i + k - 1] - position[i];
    // if i am coming back from left include left or else vice versa
    int leftNumber = abs(position[i]);
    int rightNumber = abs(position[i + k - 1]); // This is all number
     
    return min((leftNumber + getDistanceOfLine),(rightNumber + getDistanceOfLine));
   }
}

int main(){
    vector<int> x = {5,10,20};
    cout<<findMinimunTime(3,3,x)<<"\n";
}