#include <vector>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};


// This DFS problem 
int calculateMax(BinaryTree* root, int &maxValue){
  if(root == nullptr) return 0;

  int value = root->value;
  int left = calculateMax(root->left,maxValue);
  int right = calculateMax(root->right,maxValue);
  maxValue = max({maxValue,left+value,right+value,left+right+value});
  return max(value+left,value+right);
}

int maxPathSum(BinaryTree tree) {
  int maxValue = tree.value;
  calculateMax(&tree,maxValue);
  return maxValue;
}
