#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

int main() {
    Solution solution;

    // Test the reverseString function
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    
    cout << "Original String: ";
    for (char c : str) {
        cout << c;
    }
    cout << endl;

    solution.reverseString(str);

    cout << "Reversed String: ";
    for (char c : str) {
        cout << c;
    }
    cout << endl;

    return 0;
}
