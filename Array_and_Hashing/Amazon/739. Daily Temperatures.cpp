class Solution {
    //##Stack
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // will store indices of days

        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find a warmer day ahead
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack empty => no warmer day found
            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            // Push current index
            st.push(i);
        }

        return result;
    }
};