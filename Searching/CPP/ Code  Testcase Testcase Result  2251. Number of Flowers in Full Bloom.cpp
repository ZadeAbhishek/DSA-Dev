class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // basic approch is to create a hash using array 
        auto maxElement = people[max_element(people.begin(),people.end()) - people.begin()];
        vector<int> hash(maxElement+1,0);
        for(auto &range : flowers){
            for(auto i = range[0] ; i <= range[1] && i <= maxElement ; i++) hash[i]++;
        }
        vector<int> ans(people.size(),0);
        for(auto i = 0 ; i < people.size() ; i++) ans[i] = hash[people[i]];
        return ans;
    }
};
                                          
                                          
class Solution {
public:
      vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)  {
        int maxElement = *max_element(people.begin(), people.end());
        vector<int> bloomCount(maxElement + 1, 0);
​
        for (const auto &range : flowers) {
            int start = range[0];
            int end = min(range[1], maxElement);
            if (start <= maxElement)
                bloomCount[start]++;
            if (end + 1 <= maxElement)
                bloomCount[end + 1]--;
        }
​
        for (int i = 1; i <= maxElement; i++) {
            bloomCount[i] += bloomCount[i - 1];
        }
​
        vector<int> ans;
        for (const auto &person : people) {
            ans.push_back(bloomCount[person]);
        }
​
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        for(auto &x : flowers) start.push_back(x[0]), end.push_back(x[1]);
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> ans;
        for(auto &x : people){
            int startPoint = upper_bound(start.begin(),start.end(),x) - start.begin();
            int endPoint = lower_bound(end.begin(),end.end(),x) - end.begin();
            ans.push_back(startPoint - endPoint);
        }
        return ans;
    }
};