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
    vector<int> merge(vector<int> &x,vector<int> &y){
            int len1 = x.size();
            int len2 = y.size();
            vector<int> result;
            int i,j;
            i = j = 0;
            while(i < len1 && j < len2){
                if(x[i] < y[j]){
                    result.push_back(x[i]);
                    i++;
                }
                else{
                    result.push_back(y[j]);
                    j++;
                }
            }
            while(i < len1){
                result.push_back(x[i]);
                i++;
            }
              while(j < len2){
                result.push_back(y[j]);
                j++;
            }
            return result;
    }

     vector<int> sort(vector<int> &arr, int low , int high){
        vector<int> result;
            if(low == high){
              result.push_back(arr[low]);
              return result;
            }
            int mid = (low + high) / 2 ;
            vector<int> x = sort(arr,low,mid);
            vector<int> y = sort(arr,mid+1,high);
            result = merge(x,y);
    
        return result;
 }


    public:
   vector<int> MergeSort(vector<int> &arr){
     return sort(arr,0,arr.size()-1);
    }
};

int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6};   
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<"\n";
    Solution* solve = new Solution();
    vector<int> result = solve->MergeSort(List);
    for(int i = 0;i<result.size();i++){
         cout<<result[i]<<" ";
        }

}