#include<bits/stdc++.h>
using namespace std;


void operator<< (ostream& Cout, vector<vector<int>> arr)
{
    for(auto i = 0 ; i < size(arr) ; i++)
    {
        for(auto j = 0 ; j < size(arr[i]); j++) Cout<<arr[i][j]<<" ";
        Cout<<"\n";
    }
    return;
}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int> heap1(nums1.begin(),nums1.end());
        priority_queue<int> heap2(nums2.begin(),nums2.end());
        vector<vector<int>> ans;
           int x = heap1.top();
           int y = heap2.top();
             heap1.pop();
            heap2.pop();
        while(!heap1.empty() && !heap2.empty() && k > 0){
              // x is smallerst
              if(y > x){
                  ans.push_back({x,y});
                  y = heap2.top();
                  heap2.pop();
              }
              else{
                  ans.push_back({y,x});
                  x = heap1.top();
                  heap1.pop();
              }
              k--;
            }

            return ans;
        }

 int main(){
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    cout<<kSmallestPairs(nums1,nums2,3);
 }       