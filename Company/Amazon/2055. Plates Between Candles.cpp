#include <bits/stdc++.h>

using namespace std;



// this question is not compleleted
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // Your implementation here
        // Step 1 to get the all candes in the there precising candles using hashmaps 
        int stringSize = s.size();
        unordered_map<int,int> hash; // indx of candle and previous candle before current
        int counter = 0;
        for(int i = 0 ; i < stringSize ;i++) if(s[i] == '|') hash.insert({i,counter++});
        // step 2 check the range
        vector<int> result;
        for(auto windows : queries){
            int start = windows[0];
            signed int end = windows[1];

            // find the start index 
            while(start <= stringSize){
                if(hash.count(start)) break;
                else{
                    start++;
                }
            }

            // check the end 
            while(end >= -1){
                if(hash.count(end)) break;
                else end--;
            }

            if(start == stringSize || end == -1 || start >= end || start + 1 == end) result.push_back(0);
            else {
                int plates = end - start  - hash[end];
                result.push_back(plates);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Example input
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};

    // Call the function
    vector<int> result = solution.platesBetweenCandles(s, queries);

    // Print the result
    cout << "Result: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
