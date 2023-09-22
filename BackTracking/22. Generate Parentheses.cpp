#include <iostream>
#include <vector>
#include <string>
#include <chrono> // For measuring runtime

using namespace std;

class Solution {
public:
    vector<string> gp(vector<string> &vec, int open, int close, string temp) {
        if (open == 0 && close == 0) {
            vec.push_back(temp);
            return vec;
        }

        if (open == close) {
            gp(vec, open - 1, close, temp + '(');
        } else {
            if (open != 0) gp(vec, open - 1, close, temp + '(');
            gp(vec, open, close - 1, temp + ')');
        }
        return vec;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string temp = "";
        int openB = n;
        int closeB = n;
        return gp(vec, openB, closeB, temp);
    }
};

class Solution2 {
    vector<string> result;

public:
    void getcombination(string &curr, int open, int close) {
        if (open == 0 && close == 0) {
            result.push_back(curr);
            return;
        }

        if (open > close || open < 0 || close < 0) return;

        curr.push_back('(');
        getcombination(curr, open - 1, close);
        curr.pop_back();

        curr.push_back(')');
        getcombination(curr, open, close - 1);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        getcombination(temp, n, n);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution1;
    Solution2 solution2;

    // Measure the runtime of Solution 1
    auto start_time1 = chrono::high_resolution_clock::now();
    vector<string> result1 = solution1.generateParenthesis(n);
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

    // Measure the runtime of Solution 2
    auto start_time2 = chrono::high_resolution_clock::now();
    vector<string> result2 = solution2.generateParenthesis(n);
    auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);

    cout << "Using Solution 1:" << endl;
    for (const string &s : result1) {
        cout << s << endl;
    }

    cout << "Using Solution 2:" << endl;
    for (const string &s : result2) {
        cout << s << endl;
    }

    cout << "Runtime for Solution 1: " << duration1.count() << " microseconds" << endl;
    cout << "Runtime for Solution 2: " << duration2.count() << " microseconds" << endl;

    return 0;
}
