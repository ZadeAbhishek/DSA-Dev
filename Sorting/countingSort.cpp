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
         // Get maximum elements
        int max = Maxelement(arr);
        //cout<<max<<"\n";
         // create a auxillary array
        int auxarr[max+1] = {0};
        for(auto it : arr){
            auxarr[it]++;
        }
        int count = 0;
        for(auto i = 0 ; i < max+1; i++){
            if(auxarr[i] == 0)
            continue;

            while(auxarr[i]!=0){
                arr[count] = i;
                count++;
                auxarr[i]--;
            }
        }
}


   public:
   void countingSort(vector<int> &arr){
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
    solve->countingSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}