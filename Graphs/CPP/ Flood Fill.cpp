#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int color, int curr) {
        // Check if the current pixel is within the bounds of the image
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }

        // Check if the current pixel has the same color as the starting pixel
        if (image[sr][sc] != curr) {
            return;
        }

        // Change the color of the current pixel
        image[sr][sc] = color;

        // Recursively call floodFill on neighboring pixels
        floodFillHelper(image, sr + 1, sc, color, curr);
        floodFillHelper(image, sr - 1, sc, color, curr);
        floodFillHelper(image, sr, sc + 1, color, curr);
        floodFillHelper(image, sr, sc - 1, color, curr);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Check if the starting pixel has the same color as the new color
        if (image[sr][sc] == color) {
            return image;
        }

        // Call the helper function to perform the flood fill
        floodFillHelper(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};

int main() {
    // Example usage
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    Solution solution;
    vector<vector<int>> result = solution.floodFill(image, 1, 1, 2);

    // Print the result
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
