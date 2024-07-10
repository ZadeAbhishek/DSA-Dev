#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int longestPeak(vector<int> array) {
    if (array.size() < 3) return 0; // Edge case: not enough elements for a peak
    
    int maxPeak = 0;
    
    for (size_t index = 1; index < array.size() - 1; ++index) {
        int left = 0;
        int right = 0;
        
        // Calculate left slope
        for (int leftIndex = index - 1; leftIndex >= 0; --leftIndex) {
            if (array[leftIndex] < array[leftIndex + 1])
                left++;
            else
                break;
        }
        
        // Calculate right slope
        for (size_t rightIndex = index + 1; rightIndex < array.size(); ++rightIndex) {
            if (array[rightIndex] < array[rightIndex - 1])
                right++;
            else
                break;
        }
        
        // If both left and right slopes are found, calculate peak length
        if (left > 0 && right > 0) {
            int currentPeak = left + right + 1;
            maxPeak = max(maxPeak, currentPeak);
        }
    }
    
    return maxPeak;
}

// simple optimisation
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int longestPeak(vector<int> array) {
    if (array.size() < 3) return 0; // Edge case: not enough elements for a peak
    
    int maxPeak = 0;
    // optimised apporoch is to just check if there is initial peak or not
    for (size_t index = 1; index < array.size() - 1; ++index) {
        
        if(array[index] > array[index - 1] && array[index] > array[index + 1]){
        
        int left = 0;
        int right = 0;
        
        // Calculate left slope
        for (int leftIndex = index - 1; leftIndex >= 0; --leftIndex) {
            if (array[leftIndex] < array[leftIndex + 1])
                left++;
            else
                break;
        }
        
        // Calculate right slope
        for (size_t rightIndex = index + 1; rightIndex < array.size(); ++rightIndex) {
            if (array[rightIndex] < array[rightIndex - 1])
                right++;
            else
                break;
        }
        
        // If both left and right slopes are found, calculate peak length
        if (left > 0 && right > 0) {
            int currentPeak = left + right + 1;
            maxPeak = max(maxPeak, currentPeak);
        }
        }
    }
    
    return maxPeak;
}

