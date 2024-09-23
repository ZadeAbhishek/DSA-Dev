#include <iostream>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // we design direct string here
        string tape = "";
        for(auto &curr : s){
            if(curr >= 'a' && curr <= 'z') tape += curr;
            else{
                int repeat = curr - '0';
                repeat -= 1;
                string temp = tape;
                while(repeat) tape += temp, repeat--;
            }
        }
        string result = "";
        result += tape[k-1];
        return result;
    }
};

// Driver function to test the Solution class
int main() {
    Solution solution;

    // Test case 1
    string s1 = "leet2code3";
    int k1 = 10;
    cout << "Result for test case 1: " << solution.decodeAtIndex(s1, k1) << endl;  // Expected output: 'o'

    // Test case 2
    string s2 = "ha22";
    int k2 = 5;
    cout << "Result for test case 2: " << solution.decodeAtIndex(s2, k2) << endl;  // Expected output: 'h'

    // Test case 3
    string s3 = "a2345678999999999999999";
    int k3 = 1;
    cout << "Result for test case 3: " << solution.decodeAtIndex(s3, k3) << endl;  // Expected output: 'a'

    return 0;
}