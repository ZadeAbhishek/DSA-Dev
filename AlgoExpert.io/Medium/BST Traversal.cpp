#include <vector>
using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
};

void inOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
  if(tree == nullptr) return;
  inOrderTraverse(tree->left,array);
  array.push_back(tree->value);
  inOrderTraverse(tree->right,array);
  return;
}

void preOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
  if(tree == nullptr) return;
  array.push_back(tree->value);
  preOrderTraverse(tree->left,array);
  preOrderTraverse(tree->right,array);
  return;
}

void postOrderTraverse(BST* tree, vector<int>& array) {
  // Write your code here.
  if(tree == nullptr) return;
  postOrderTraverse(tree->left,array);
  postOrderTraverse(tree->right,array);
  array.push_back(tree->value);
  return;
}
