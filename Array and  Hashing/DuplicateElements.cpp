#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

class Solution {
unordered_map<int,int> table;
public:
     bool containsDuplicateSoutionTwo(vector<int>& nums) {
            // idea is to use hashmap 
            // Tc: O(n) sc: O(n)
            int len = nums.size();
            int index = 0;
            while(index!=len){
                if(table.count(nums[index])){
                    return true;
                }
                table.insert({nums[index],nums[index]});
                index++;
                
            }
            return false;
     }
     bool containsDuplicateRecursive(vector<int>& nums) {
            // idea is to use hashmap 
            // Tc: O(n) sc: O(n)
            bool result = search(nums,0);
            return result;
     }

     bool search(vector<int>& nums, int index){
           if(table.count(nums[index]) ){
                    return true;
            }
           if(index == nums.size()){
             return false;
           }
                table.insert({nums[index],nums[index]});
                search(nums,index+1);
}

    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        int fast = 0;
        int slow = 0;
        int i = 0;
        while(i != size(nums)-1){
            fast = nums[nums[fast]];
            slow = nums[slow];
            i++;
            if(fast == slow && fast != len) return true;
            else break;
        }
        return false;
    }

     bool containsDuplicateThree(vector<int>& nums) {
            
            int temp_var = 0;

            for(auto i = 0 ; i < size(nums) ; i++) 
            {
                temp_var = temp_var ^ nums[i];
                cout<<temp_var<<" ";
            }
            return true;   

    }
};

int main (){
     
     
     vector<int> List = {1,2,3,4,5,6,7};
     int len = List.size();
     for(int i = 0;i<len;i++){
         cout<<List[i]<<" ";
        }
       cout<<endl;
    Solution* solve = new Solution();    
    bool result = solve->containsDuplicate(List);
    cout<<result<<" "<<endl;

}