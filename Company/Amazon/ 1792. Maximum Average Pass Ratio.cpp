class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Corrected comparator struct
        struct cmp {
            bool operator()(pair<double,double> a, pair<double,double> b) {
                double aDx = ( (a.first + 1) / (a.second + 1) ) - ( a.first / a.second );
                double bDx = ( (b.first + 1) / (b.second + 1) ) - ( b.first / b.second );
                return aDx < bDx;
            }
        };

        // Priority queue
        priority_queue<pair<double,double>, vector<pair<double,double>>, cmp> que;

        // Fill the priority queue with pairs converted to double
        for (auto& c : classes) {
            que.push({double(c[0]), double(c[1])});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto top = que.top();
            que.pop();
            que.push({top.first + 1, top.second + 1});
        }

        // Calculate the total passing ratio
        double totalPassingRatio = 0;
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            totalPassingRatio += (top.first / top.second);
        }

        // Return the average passing ratio
        return totalPassingRatio / classes.size();
    }
};
