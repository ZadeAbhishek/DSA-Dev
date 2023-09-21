#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        // BFS should work here
        std::queue<int> rooms_to_visit;

        // Lock buffer
        std::vector<int> lock(rooms.size(), 1);

        // Since I can visit only room 0 at the start
        for (auto it : rooms[0]) {
            rooms_to_visit.push(it);
        }

        lock[0] = 0;

        while (!rooms_to_visit.empty()) {
            int key = rooms_to_visit.front();
            rooms_to_visit.pop();
            if (lock[key]) {
                lock[key] = 0;
                for (auto it : rooms[key]) {
                    rooms_to_visit.push(it);
                }
            }
        }

        for (auto &it : lock) {
            if (it == 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    bool canVisit = solution.canVisitAllRooms(rooms);
    
    if (canVisit) {
        std::cout << "You can visit all rooms!" << std::endl;
    } else {
        std::cout << "You cannot visit all rooms." << std::endl;
    }

    return 0;
}
