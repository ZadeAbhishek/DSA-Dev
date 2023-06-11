// Same floyd's Hair and Rabit problem
// FInd the same repeating number in array 
// Only one number in array is going to repeat
#include <iostream>

#include <vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector <int> Array{};
        if(nums == Array){return NULL;}
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        // cout<<slow<<"--"<<fast<<endl;
        int slow2 = 0;
        while(true){
          slow2= nums[slow2];
          slow = nums[slow];
          if(slow2 == slow){
            return slow;
      }
    }
        return 0;
  }
        
  };

int main (){
 vector <int> Array{1,3,4,2,2};
  cout<<endl;
  Solution* solve = new Solution();
  int result = solve->findDuplicate(Array);
  cout<<result;
}