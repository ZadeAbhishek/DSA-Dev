#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> counter(10, 0); // Initialize counter array with size 10 and all elements set to 0
        // Get digits
        while (num) {
            counter[num % 10]++;
            num /= 10;
        } 

        int nums1 = 0;
        int nums2 = 0;
        int turn = 0; // 0 means nums1 chance else nums2

        for (int i = 0; i <= 9; i++) {
            while (counter[i]) {
                if (turn == 0) {
                    nums1 += i;
                    if (nums1 != 0) nums1 *= 10;
                }
                if (turn == 1) { 
                    nums2 += i; 
                    if (nums2 != 0) nums2 *= 10;
                }
                turn = !turn;
                counter[i]--;
            }
        }

        nums1 /= 10;
        nums2 /= 10;

        return nums1 + nums2; 
    }
};

class Solution2 {
public:
    int minimumSum(int num) {
        string temp = to_string(num);
        sort(temp.begin(),temp.end());
        return (((temp[0] - '0')+(temp[1] - '0'))*10 + ((temp[2]-'0') + (temp[3]-'0')));
    }
};

int main() {
    Solution solution;
    int input = 2392; // Example input
    int result = solution.minimumSum(input);
    cout << "Result: " << result << endl;
    return 0;
}
