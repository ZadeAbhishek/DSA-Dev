#include <iostream>
#include <string>

class Solution {
public:
    int bestClosingTime(std::string customers) {
        int max_score = 0, score = 0, best_hour = -1;

        // Iterate through each hour
        for (int i = 0; i < customers.size(); ++i) {
            // Update the score based on the customer type ('Y' or 'N')
            score += (customers[i] == 'Y') ? 1 : -1;

            // Check if the current score is higher than the maximum score
            if (score > max_score) {
                max_score = score;
                best_hour = i;
            }
        }

        // Return the best closing hour (add 1 to convert from 0-based index to 1-based index)
        return best_hour + 1;
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    std::string customers = "YYYNNYNNYNNYY";
    int bestHour = solution.bestClosingTime(customers);

    // Display the best closing hour
    std::cout << "The best closing hour is at: " << bestHour << " o'clock." << std::endl;
    
    return 0;
}
