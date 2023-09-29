#include<bits/stdc++.h>
using namespace std;



void operator<< (ostream& Cout, set<vector<int>> s){
    for(auto x : s){
        for(auto j : x){
            Cout<<j<<" ";
        }
        Cout<<"\n";
    }
}

class Solution{

  

  public:


 int triplates_approch_2(vector<int> &arr, int target,set<vector<int>> &s){
    // we will sort the array in beginig 
    sort(arr.begin(),arr.end());
    vector<int> temp;
    int m = INT_MAX;
    for(auto i = 0 ; i < arr.size(); i++){
        int curr = arr[i];
        int left = i + 1;
        int right = arr.size()-1;
        while(left < right){
            int sum = curr + arr[left] + arr[right];
            if(m > abs(sum-target)){
                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
                temp.push_back(curr);
                s.insert(temp);
                m = abs(sum-target);
                left++;
                right--;
                temp.clear();
            }
            else if(sum < target) left++;
            else right--;
            }
    }
    return m;
    // o(n^2)
 }

};



int main(){
   vector<int> arr = {-1,2,1,-4};
   Solution *s;
   set<vector<int>> t;
   cout<<s->triplates_approch_2(arr,1,t)<<endl;
   cout<<t;
}


