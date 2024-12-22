class Solution {
    //##Stack
public:
    string decodeString(string s) {
        // Stack to store characters
        stack<char> st;

        for (auto c : s) {
            if (c == ']') {
                // Extract the substring within the brackets
                string tempStr = "";
                while (!st.empty() && st.top() != '[') {
                    tempStr += st.top();
                    st.pop();
                }
                reverse(tempStr.begin(), tempStr.end()); // Reverse since we retrieved it backwards
                st.pop(); // Remove the '['

                // Extract the number before the brackets
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr += st.top();
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end()); // Reverse since we retrieved it backwards
                int count = stoi(numStr); // Convert to integer

                // Push the repeated substring back onto the stack
                string repeatedStr = "";
                for (int i = 0; i < count; i++) {
                    repeatedStr += tempStr;
                }
                for (auto ch : repeatedStr) {
                    st.push(ch);
                }
            } else {
                // Push current character to the stack
                st.push(c);
            }
        }

        // Extract the final result from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); // Reverse to get the correct order
        return result;
    }
};