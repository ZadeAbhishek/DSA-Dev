
// ##BitManipulation
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> temp(cells.size(), 0);
        vector<vector<int>> cycle;
        
        while (n--) {
            for (int i = 1; i < cells.size() - 1; i++) {
                // Set temp[i] to 1 if neighbors are the same, else 0
                temp[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
            }
            
            // Check if the current pattern has been seen before to detect a cycle
            if (!cycle.empty() && cycle.front() == temp) {
                // Use modulo to find the result after all cycles
                return cycle[n % cycle.size()];
            } else {
                cycle.push_back(temp);
            }

            // Update cells to the new day’s state
            cells = temp;
        }
        
        return cells;
    }
};