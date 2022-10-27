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
    void shift(vector<int> &arr, int i , int j){
       // shift element from i to n
      // cout<<i<<"\n";
       int t = i;
       int temp = arr[i];
       i++;
       while(i <= arr.size()-1){
          int t = arr[i];
          arr[i] = temp;
          temp = t;
          i++;
    }
    arr[t] = j;
}
     void sort(vector<int> &arr){
          // create a function for shifting
          // check elements
          int i,j;
          i = 0;
          j = arr.size() - 1;
          while(i != j){
            if(arr[j] > arr[i]){
                shift(arr,i+1,arr[j]);
                //printVector(arr);
            }
            else{
                //cout<<i<<'\n';
                int ix = i;
                while(ix >= 0){
                    if(arr[ix] < arr[j]){
                        shift(arr,ix+1,arr[j]);
                      //  printVector(arr);
                        break;
                    }
                    if(ix == 0){
                        shift(arr,ix,arr[j]);
                       // printVector(arr);
                        break;
                    }
                    ix--;
                }
            }
            printVector(arr);
            i++;
          }
     }


   public:
   void InsertionSort(vector<int> &arr){
     sort(arr);
     return;
    }
};

int main (){
     vector<int> List = {7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6,0,-1};   
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<"\n";
    Solution* solve = new Solution();
    solve->InsertionSort(List);
    for(int i = 0;i<List.size();i++){
         cout<<List[i]<<" ";
        }

}