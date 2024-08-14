#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    unordered_map<int, vector<pair<int, int>>> hash;
    set<vector<int>> result;
    vector<vector<int>> finalResult;

    // Store pairs and their sums in hash
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            int sum = array[i] + array[j];
            hash[sum].emplace_back(array[i], array[j]);
        }
    }

    // Check the combinations
    for (auto &x : hash) {
        int curr = targetSum - x.first;

        // Skip if the sum equals its complementary part to avoid using the same pair
        if (curr == x.first) continue;

        if (hash.count(curr)) {
            for (auto &p1 : x.second) {
                for (auto &p2 : hash[curr]) {
                    // Ensure all elements are distinct
                    if (p1.first != p2.first && p1.first != p2.second &&
                        p1.second != p2.first && p1.second != p2.second) {
                        vector<int> temp = {p1.first, p1.second, p2.first, p2.second};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                }
            }
        }
    }

    for (auto &x : result) {
        finalResult.push_back(x);
    }

    return finalResult;
}



// O(n^3) worst case time complexity
// O(n^2) space complexity
#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  vector<vector<int>> result;
  sort(array.begin(),array.end());
  for(int i = 0 ; i < array.size(); i++){
    if(i > 0 && array[i] == array[i-1]) continue; // skip it
    for(int j = i + 1 ; j < array.size(); j++){
      if(j != (i + 1) && array[j] == array[j-1]) continue;
      int k = j + 1;
      int l = array.size() - 1; // point to last
      while(k < l){
        long long sum = array[i];
        sum += array[j];
        sum += array[k];
        sum += array[l];
        if(sum == targetSum){
          vector<int> temp = {array[i],array[j],array[k],array[l]};
          k++;
          l--;
          while(k < l && array[k] == array[k+1]) k++;
          while(k < l && array[l] == array[l-1]) l--;
        }
        else if(sum < targetSum){
          k++;
        }
        else l--;
       }
    }
  }
  return result;
}
