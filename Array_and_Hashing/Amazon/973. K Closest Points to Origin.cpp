class Solution {
public:
    int getDistance(int x, int y) {
        // Return squared distance to avoid floating-point issues
        return (x * x) + (y * y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(size_t i = 0 ; i < points.size(); i++){
            int dist = getDistance(points[i][0],points[i][1]);
             pq.push({dist,i});
        }
        vector<vector<int>> result;
        while(k--){
          auto top = pq.top();
          pq.pop();
          result.push_back(points[top.second]);
        }
        return result;
    }
};