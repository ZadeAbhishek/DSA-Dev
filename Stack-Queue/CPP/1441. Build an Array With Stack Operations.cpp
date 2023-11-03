class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int targetIndex = 0;
        int currNum = 1;

        while (targetIndex < target.size()) {
            switch (target[targetIndex] - currNum) {
                case 0:
                    operations.push_back("Push");
                    targetIndex++;
                    break;
                default:
                    operations.push_back("Push");
                    operations.push_back("Pop");
            }
            currNum++;
        }

        return operations;
    }
};