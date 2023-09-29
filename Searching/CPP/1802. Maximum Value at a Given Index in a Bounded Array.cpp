/* https://www.youtube.com/watch?v=MjpAAE3-hYg&ab_channel=CherryCoding%5BIIT-G%5D */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // binary search 
        long high = maxSum;
        long low = 1;


        long r = n - index - 1;   // for ex 6 - 1 - 1 = 4 this represents total spaces in right side 
        long l = index; // for ex 1
        long result; 

        while(high >= low){
            long mid = (high - low)/2 + low;
            long sum = mid;
            long leftSum = 0;
            long rightSum = 0;
            long m = mid-1;
            

            if(r<=m){
                rightSum = m*(m + 1)/2 - (m-r)*(m-r+1)/2;
            }
            else rightSum = m*(m + 1)/2 + (r-m);

             if(l<=m){
                leftSum = m*(m + 1)/2 - (m-l)*(m-l+1)/2;
            }
            else leftSum = m*(m + 1)/2 + (l-m);

            sum += leftSum + rightSum;

            //if(sum == maxSum) break;
            
            if(sum <= maxSum)  result=mid ,low = mid + 1;

            else high = mid-1;
        }
        return result; 
    }
};

int main (){
    int n = 6;
    int index = 1;
    int ms = 10;

    Solution *solve;

    cout<<solve->maxValue(6,1,10)<<endl;
}