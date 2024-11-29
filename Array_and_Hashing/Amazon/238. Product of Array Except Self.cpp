class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preffix(n, 1); // Store prefix products
        vector<int> suffix(n, 1); // Store suffix products

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            preffix[i] = preffix[i - 1] * nums[i - 1];
        }

        // Calculate suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Calculate the final product array
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = preffix[i] * suffix[i];
        }

        return result;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize the result array with 1

        // First pass: Calculate prefix products and store them in the result array
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // Second pass: Calculate suffix products on the fly and multiply with prefix products in result array
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix; // Multiply the stored prefix product with the current suffix product
            suffix *= nums[i];   // Update the suffix product
        }

        return result;
    }
};