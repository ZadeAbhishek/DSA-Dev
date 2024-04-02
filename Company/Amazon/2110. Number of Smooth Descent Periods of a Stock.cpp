#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

#include <vector>
#include <stack>

using namespace std;

// this is stack version
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        // edge case 
        if(prices.size() < 1) return 0;
        else if(prices.size() == 1) return 1; 
        // step 1 is to count all premutation if we get any desend
        prices.push_back(INT_MAX);
        stack<int> st;
        long long sizeOfArray = prices.size();
        st.push(prices[0]);
        long long count = sizeOfArray;
        for(auto i = 1 ; i < sizeOfArray ; i++){
            //always start from 1
            int curr = st.top();
            if(curr - prices[i] == 1) st.push(prices[i]);
            else{
                long long stackSize = st.size();
                count += (((stackSize) * (stackSize + 1))/2) - stackSize;
                // empty the stack
                while(!st.empty()) st.pop();
                st.push(prices[i]);
            } 
        }
        return count - 1;
    }
};


// without stack version
class Solution2 {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if(prices.size() < 1) return 0;
        else if(prices.size() == 1) return 1;
        prices.push_back(INT_MAX); // for edges case
        int arraySize = prices.size();
        long long count = prices.size();
        // false stack (basically we are swapping the top here)
        long stackTop = prices[0];
        long long stackSize = 1;
        for(int index = 1; index < arraySize ; index++){
             if(stackTop - prices[index] == 1) stackTop = prices[index], stackSize++;
             else{
                count += (((stackSize) * (stackSize + 1))/2) - stackSize;
                stackSize = 1;
                stackTop = prices[index];
             }
        }
        return count - 1;

    }
};

int main() {
    Solution2 solution;
    vector<int> prices = {3,2,1,4};
    cout << "Descent periods count: " << solution.getDescentPeriods(prices) << endl;
    return 0;
}
