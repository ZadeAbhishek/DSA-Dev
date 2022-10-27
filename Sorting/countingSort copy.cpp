#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> result){
         for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }
        cout<<"\n";
    }

class Solution {
    private:
    int Maxelement(vector<int> &arr){
        int max = INT_MIN;
        for(auto it : arr){
            if(it > max)
            max = it;
        }
        return max;
    }
     
     void sort(vector<int> &arr){
       // idea is to implement the bucket
       // get maximum element
       int m = Maxelement(arr);
       // count digit
       int digit = 1
       for(int div = 1 ; m/div > 0 ; div *= 10){
          digit *= 10;
       }

       // creating buket using hashmaps
       unordered_map<int,vector<int>> table; 
       for(auto i = 0 ; i < 10 ; i++){
            vector<int> 
       }

}


   public:
   void BucketSort(vector<int> &arr){
     sort(arr);
     return;
    }
};

int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6,0};
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<"\n";
    Solution* solve = new Solution();
    solve->BucketSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}