#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // edge case
        string temp = "";
        int newStringSize =  s.size();
        int spacesCount = spaces.size();
        for (int index = 0; index < newStringSize; index++) {
            if (spacesCount > 0 && index == spaces[spaces.size() - spacesCount]) {
                temp += ' ';
                spacesCount--;
            }
            temp += s[index];
        }
        return temp;
    }
};

int main() {
    Solution solution;
    string s = "hello";
    vector<int> spaces = {0,1,2,3,4,5,6};
    string result = solution.addSpaces(s, spaces);
    cout << "Result: " << result << endl;
    return 0;
}
