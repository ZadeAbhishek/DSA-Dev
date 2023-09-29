#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        stack<int> s;

        // Push all candidates onto the stack
        for (int i = 0; i < n; i++)
            s.push(i);

        // Until the size of the stack is not one, compare top two candidates
        // and eliminate one who knows the other
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (M[a][b])
                s.push(b);
            else
                s.push(a);
        }

        // Verify potential candidate
        int candidate = s.top();
        int VzeroCount = 0; // Count of zeros in the candidate's column
        int HzeroCount = 0; // Count of zeros in the candidate's row

        // Check how many people the candidate knows and how many know the candidate
        for (int i = 0; i < n; i++) {
            if (M[candidate][i] == 0)
                VzeroCount++;
            if (M[i][candidate] == 1)
                HzeroCount++;
        }

        // Check if the potential candidate satisfies the conditions for being a celebrity
        if (VzeroCount == n && HzeroCount == n - 1)
            return candidate; // The candidate is a celebrity

        return -1; // No celebrity found
    }
};

int main() {
    Solution solution;

    // Example input: a matrix representing the relationships
    vector<vector<int>> relationships = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };
    int n = relationships.size();

    int celebrityIndex = solution.celebrity(relationships, n);
    if (celebrityIndex != -1) {
        cout << "Celebrity found at index " << celebrityIndex << endl;
    } else {
        cout << "No celebrity found in the party." << endl;
    }

    return 0;
}
