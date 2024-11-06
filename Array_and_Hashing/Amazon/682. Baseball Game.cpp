class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> sum;
        
        for(auto& x : operations) {
            if(x == "C") {
                // Remove the last score
                if (!sum.empty()) sum.pop();
            }
            else if(x == "D") {
                // Double the last score and push it onto the stack
                if (!sum.empty()) sum.push(2 * sum.top());
            }
            else if(x == "+") {
                // Add the last two scores
                int top = sum.top();
                sum.pop();
                int newTop = top + sum.top();
                sum.push(top);       // Push back the previous top score
                sum.push(newTop);     // Push the new score
            }
            else {
                // Convert string to integer and push onto the stack
                sum.push(stoi(x));
            }
        }

        int total = 0;
        while(!sum.empty()) {
            total += sum.top();
            sum.pop();
        }
        
        return total;
    }
};