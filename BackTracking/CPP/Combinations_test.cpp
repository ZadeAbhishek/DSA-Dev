#include <vector>
#include <iostream>

void printCombinations(const std::vector<int>& numbers, unsigned size, std::vector<int>& line) {
    for (unsigned i = 0; i < numbers.size(); i++) {
        line.push_back(numbers[i]);
        if (size <= 1) { // Condition that prevents infinite loop in recursion
            for (const auto& j : line)
                std::cout << j << ","; // Simplified print to keep code shorter
            std::cout << std::endl;
            line.erase(line.end() - 1);
        } else {
            printCombinations(numbers, size - 1, line); // Recursion happens here
            line.erase(line.end() - 1);
        }
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3};
    unsigned size = 3;
    std::vector<int> line;
    printCombinations(numbers, size, line);
    return 0;
}