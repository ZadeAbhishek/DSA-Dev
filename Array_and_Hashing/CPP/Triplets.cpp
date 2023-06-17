#include<bits/stdc++.h>
using namespace std;



void operator<< (ostream& Cout, set<vector<int>> s){
    for(auto x : s){
        for(auto j : x){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

class Solution{

  

  public:
 set<vector<int>> triplates_approch_1(vector<int> &arr){
     
     // using for loop O(n^2)
     set<vector<int>> s;

     for(auto i = 0 ; i < arr.size() - 2 ; i++){
        for(auto j = i+1 ; j < arr.size() - 1; j++){
            for(auto k = j+1 ; k < arr.size(); k++){
                vector<int> temp;

                if(arr[i] + arr[j] + arr[k] == 0){
                       temp.push_back(arr[i]);
                       temp.push_back(arr[j]);
                       temp.push_back(arr[k]);
                       sort(temp.begin(),temp.end()); // n log n
                       s.insert(temp);

                }
            }
        }
     }
     return s;
    // n log n + n^3
 }


 set<vector<int>> triplates_approch_2(vector<int> &arr){
    // we will sort the array in beginig 
    sort(arr.begin(),arr.end());
    set<vector<int>> s;
    vector<int> temp;
    for(auto i = 0 ; i < arr.size(); i++){
        int curr = arr[i];
        int left = i + 1;
        int right = arr.size()-1;
        while(left < right){
            if(curr + arr[left] + arr[right] == 0){
                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
                temp.push_back(curr);
                s.insert(temp);
                left++;
                right--;
                temp.clear();
            }
            else if(curr + arr[left] + arr[right] < 0) left++;
            else right--;
            }
    }
    return s;
    // o(n^2)
 }


set<vector<int>> triplates_approch_3(vector<int> &arr,vector<int> temp,set<vector<int>> &hash,vector<bool> &memo){
   // base case
   if(temp.size() > 3) return hash;
   if(temp.size() == 3){
     if(temp[0] + temp[1] + temp[2] == 0){
        sort(temp.begin(),temp.end());
        hash.insert(temp);
     }
   }

   // iterator
   for(auto i = 0 ; i < arr.size(); i++){
    if(!memo[i]){
        memo[i] = true;
        temp.push_back(arr[i]);
        triplates_approch_3(arr,temp,hash,memo);
        temp.pop_back();
        memo[i] = false;
    }
   }
   return hash;

}

};



int main(){
   vector<int> arr = {-1,0,1,2,-1,-4};
   vector<int> temp;
   set<vector<int>> hash;
   vector<bool> memo(arr.size(),false);
   Solution *s;
   cout<<s->triplates_approch_3(arr,temp,hash,memo);

}