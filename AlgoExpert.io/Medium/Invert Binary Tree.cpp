#include <vector>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) {
  // Write your code here.
  // base condition 
  if(tree == nullptr) {
    return;
  }
  // main condition
  invertBinaryTree(tree->left);
  invertBinaryTree(tree->right);
  BinaryTree* temp = tree->left; // may be nullptr
  tree->left = tree->right;
  tree->right = temp;
  return;
}
