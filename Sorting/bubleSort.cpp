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

     void sort(vector<int> &arr){
        // basically swap
        int pass = arr.size()-1;
        while(pass!=0){
            int i = 0;
            int j =1;
            while(i < pass){
                if(arr[i] >= arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                i++;
                j++;
            }
            printVector(arr);
            pass--;
        }

     }


   public:
   void BubleSort(vector<int> &arr){
     sort(arr);
     return;
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
    solve->BubleSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}