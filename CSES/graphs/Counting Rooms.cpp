/*
Time limit: 1.00 s
Memory limit: 512 MB



You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;


// traverse each element in matrix and if floor ->> bfs to traverse neigboe and mark them # on each
// itreation increase the count of rooms
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> base(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;  // Read each row as a string
        for (int j = 0; j < m; j++) {
            base[i][j] = line[j];
        }
    }
    
    int rooms = 0;
    vector<vector<int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // moved outside loops for efficiency

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (base[i][j] == '.') {
                rooms++;
                queue<pair<int,int>> bfsQueue;
                bfsQueue.push({i,j});
                base[i][j] = '#';  // Mark as visited immediately

                while (!bfsQueue.empty()) {
                    auto [currX, currY] = bfsQueue.front();
                    bfsQueue.pop();

                    for (auto &d : direction) {
                        int newX = currX + d[0];
                        int newY = currY + d[1];
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && base[newX][newY] == '.') {
                            bfsQueue.push({newX, newY});
                            base[newX][newY] = '#';  // Mark neighbor as visited
                        }
                    }
                }
            }
        }
    }
    
    cout << rooms << endl;
    return 0;
}