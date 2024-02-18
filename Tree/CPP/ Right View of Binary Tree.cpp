#include <iostream>
#include <vector>
#include <map>
#include <chrono> // For time measurements

using namespace std;
using namespace std::chrono; // For time measurements

// Definition for a binary tree node.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Solution Class
class Solution {
public:
    void traverse(Node* root, int level, map<int,int> &hash) {
        // base
        if(root == NULL) return;
        
        // check if level already present
        // if not add it
        if(hash.find(level) == hash.end()) 
            hash.insert({level,root->data});
        
        traverse(root->right, level + 1, hash);
        traverse(root->left, level + 1, hash);
        
        return;
    }

    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // hash to store level wise order
        map<int,int> hash;
        
        traverse(root, 0, hash);
        
        vector<int> ans;
        
        for(auto &x : hash) 
            ans.push_back(x.second);
        
        return ans;
    }

    // Function to search for a value in the binary tree
    bool search(Node *root, int target) {
        if (root == nullptr)
            return false;

        if (root->data == target)
            return true;

        return search(root->left, target) || search(root->right, target);
    }
};

// Driver Function
int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    Solution sol;

    // Get the right view of the tree
    vector<int> result = sol.rightView(root);

    // Print the right view elements
    cout << "Right View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Measure time taken by search function
    int target = 4;
    auto start = high_resolution_clock::now();
    bool found = sol.search(root, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Search for value " << target << " took: " << duration.count() << " microseconds." << endl;
    if (found)
        cout << "Value " << target << " found in the tree." << endl;
    else
        cout << "Value " << target << " not found in the tree." << endl;

    // Clean up memory
    delete root->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
