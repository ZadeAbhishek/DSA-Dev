class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            int num1 = nums[i];
            for(int j = i+1 ; j < nums.size(); j++){
                if(nums[j] > num1){
                    int num2 = nums[j];
                    for(int k = j + 1; k < nums.size(); k++){
                        if(nums[k] > num1 && nums[k] < num2) return true;
                    }
                }
            }
        }
        return false;
    }
};


// in this approch stack in used to access the current highest element than nums[i] i.e k.
// Queue might fail as it will last highesy number not current highest number than nums[i] i.e k
// k becuase we are travelling in reverse order here 
// ##Stack
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num3 = INT_MIN;
        stack<int> st;
        for(int i = nums.size()-1 ; i >= 0; i--){
            // check if current number is less than nums3
            if(nums[i] < num3) return true;
            else{
                while(!st.empty() && nums[i] > st.top()){
                    num3 = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// 3 1 4 2 // num3 = 2
// 4
// 1