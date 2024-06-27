using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void traverse(BinaryTree* root, int sum, vector<int>& ans){
    
   
   if(root == nullptr) return; 
   if(root->left == nullptr && root->right == nullptr){
       ans.push_back(sum  + root->value);
       return;
   }
     
   traverse(root->left,sum+root->value,ans);
   traverse(root->right,sum+root->value,ans);
   
  return;  
}

vector<int> branchSums(BinaryTree* root) {
  // Write your code here.
  vector<int> ans;
   traverse(root,0,ans);
  return ans;
}


// iterative approch 

#include <vector>
#include <stack>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> branchSums(BinaryTree* root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  stack<pair<BinaryTree*, int>> stack;
  stack.push({root, 0});

  while (!stack.empty()) {
    auto [node, currentSum] = stack.top();
    stack.pop();

    int newSum = currentSum + node->value;

    // Check if it's a leaf node
    if (node->left == nullptr && node->right == nullptr) {
      ans.push_back(newSum);
    } else {
      // Push the children with the updated sum
      if (node->right != nullptr) {
        stack.push({node->right, newSum});
      }
      if (node->left != nullptr) {
        stack.push({node->left, newSum});
      }
    }
  }

  return ans;
}
