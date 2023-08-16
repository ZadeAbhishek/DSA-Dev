#include <iostream>
#include <bits/stdc++.h> // Includes required headers
using namespace std;


class Solution {
public:
    string rearrangeString(string s) {
        // Edge case: An empty string has no characters to rearrange
        if (s.empty())
            return "";

        // Create a hash table to store character frequencies
        vector<int> hash(26, 0);

        // Count the frequency of each character in the input string
        for (auto &x : s)
            hash[x - 'a']++;

        // Create a max-heap (priority queue) of pairs: frequency and character
        priority_queue<pair<int, char>> heap;

        // Populate the heap with characters and their frequencies
        for (auto x = 0; x < 26; x++)
        {
            if (hash[x] == 0)
                continue;
            heap.push({hash[x], (char)(x + 'a')});
        }

        // Reorganize the string by repeatedly selecting characters
        // with the highest frequency from the heap and forming a new string
        string ans = "";
        auto prev = heap.top(); // Get the character with the highest frequency
        heap.pop();
        prev.first--; // Decrement the frequency count
        ans += prev.second; // Append the character to the result string
        while (!heap.empty() && heap.top().first)
        {
            auto next = heap.top(); // Get the next character with the highest frequency
            heap.pop();
            next.first--; // Decrement the frequency count
            ans += next.second; // Append the character to the result string
            heap.push(prev); // Put the previous character back in the heap
            prev = next; // Update the previous character
        }

        // If the heap is empty and there's still a character with a frequency > 0
        if (!heap.empty() && prev.first > 0)
            return ""; // Cannot reorganize the string

        if (heap.empty() && prev.first > 0)
            return ""; // Cannot reorganize the string    

        return ans; // Return the reorganized string
    }
};


int main()
{
    Solution solution;

    std::string input = "geeksforgeeks";
    std::string result = solution.rearrangeString(input);

    if (result.empty())
    {
        std::cout << "Cannot reorganize the string.\n";
    }
    else
    {
        std::cout << "Reorganized string: " << result << "\n";
    }

    return 0;
}
