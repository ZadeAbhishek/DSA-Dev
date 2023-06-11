#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // binary search 
        int high = size(letters)-1;
        int low = 0;
        int mid = 0;
        char ans;
        
        if(target < letters[0]) return letters[0];
        if(target >= letters[letters.size()-1]) return letters[0];
        
        while(high >= low){
           mid = (high + low)/2;

           if(letters[mid] > target) ans = letters[mid] , high = mid-1;

           else low = mid+1; 

    }
    return ans;
    }
};

// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {

//         int low=0;
//         int high=letters.size()-1;
        
//         if(letters[0] > target)
//           return letters[0];

//         else if(target >= letters[letters.size()-1])
//         return letters[0];  

//         char ans;  
        
//         while( low <= high)
//         {
//             int mid=(low+high)/2;
            
//              if(letters[mid] > target){
//                  ans = letters[mid];
//                  high = mid-1;
//              }

//              else
//              low = mid+1;

//         }
        
//         return ans;
        
//     }
// };

int main(){
    vector<char> letters = {'c','f','k'};
    Solution *solve;
    cout<<solve->nextGreatestLetter(letters,'c')<<endl;
    
}