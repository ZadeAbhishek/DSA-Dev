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
        int maxi = INT_MIN;
        for(auto it : arr) maxi = max(it,maxi);
        return maxi;
    }

     void Bucketsort(vector<int> &arr){
       // idea is to implement the bucket
       
       // step 1 Find the max element
       int m = Maxelement(arr);
       
       // step 2 count digit in max element
       int div = 10, count = 0, digit = 1;
       while(m > 0) m /= div, div *= 10 , count++;
       while(count != 0) digit *= 10,count--; 
       
       //step 3 Creating buket using hashmaps
       unordered_map<int,vector<int>> table;
       for(auto i = 10 ; i > 0 ; i--) table.insert({i,{}});

       // step 4 
       // itr arr and push element to there bucket
       // for example if number is 700
       // 700/digit = 700/100 = 7 insert in 7th bucket
       for(auto it : arr) table[it/digit].push_back(it);

       // step 5 sort each element in table
       for(auto curr : table) sort(begin(table[curr.first]),end(table[curr.first]));
       

       //step 6 push back to original array
       arr.clear();
       for(auto irr : table) arr.insert(arr.end(), irr.second.begin(), irr.second.end());

}


   public:
   void Bucket(vector<int> &arr){
     Bucketsort(arr);
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
    solve->Bucket(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}