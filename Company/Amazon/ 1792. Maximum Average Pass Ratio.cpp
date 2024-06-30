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


// chatGpt optimisation

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Comparator for the priority queue to prioritize based on the gain in pass ratio
        auto cmp = [](pair<double, double>& a, pair<double, double>& b) {
            double gainA = ((a.first + 1) / (a.second + 1)) - (a.first / a.second);
            double gainB = ((b.first + 1) / (b.second + 1)) - (b.first / b.second);
            return gainA < gainB;
        };

        // Priority queue to store pairs of {pass, total} with the custom comparator
        priority_queue<pair<double, double>, vector<pair<double, double>>, decltype(cmp)> pq(cmp);

        // Fill the priority queue with the initial classes
        for (const auto& c : classes) {
            pq.push({static_cast<double>(c[0]), static_cast<double>(c[1])});
        }

        // Distribute extra students to maximize the average pass ratio
        while (extraStudents--) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.push({pass + 1, total + 1});
        }

        // Calculate the total passing ratio
        double totalPassingRatio = 0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            totalPassingRatio += pass / total;
        }

        // Return the average passing ratio
        return totalPassingRatio / classes.size();
    }
};

