#include<bits/stdc++.h>
using namespace std;

void operator<< (ostream& Cout , vector<int> arr){
   for(auto x : arr){
    Cout<<x<<" ";
   }
   Cout<<endl;
}

void nextGreastesElement(vector<int> arr, vector<int> &result){
    stack<int> s;
    for(auto i = size(arr)-1; i > 0; i-- ){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(s.empty()) result[i] = size(arr)-1; 
        else result[i] = s.top() - 1;
        s.push(i);  
    }
}

int main(){
    vector<int> arr = {2,1,5,6,2,3,1};
    vector<int> result(size(arr),0);
    nextGreastesElement(arr,result);
    cout<<result;

}