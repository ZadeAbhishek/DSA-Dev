class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Basic solution
        int MaxProfit = INT_MIN;
        int n = prices.size();
        for(auto i = 0 ; i < n ; i++){
            for(auto j = i ; j < n; j++){
                 MaxProfit = max(MaxProfit,(prices[j]-prices[i]));
            }
        }
        return MaxProfit == INT_MIN ? 0 : MaxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int maxProfit = INT_MIN;
        for(auto x : prices){
            if(!st.empty()){
                if(x > st.top()) maxProfit = max(maxProfit,(x - st.top()));
                else{
                    while(!st.empty() && x <= st.top()) st.pop();
                    if(st.empty()) st.push(x);
                }
            }
            else st.push(x);
        }
        return maxProfit == INT_MIN?0:maxProfit;
    }
};