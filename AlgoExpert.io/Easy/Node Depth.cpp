#include<queue>
#include<utility>
using namespace std;

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

int nodeDepths(BinaryTree* root) {
  // Write your code here.
 // we can use stack here
// base condition
 if(root == nullptr) return 0;
queue<pair<BinaryTree*,int>> nodeStack;
int sum = 0;
nodeStack.push({root,0});
while(!nodeStack.empty()){
 auto currNode = nodeStack.front();
 nodeStack.pop();
 sum += currNode.second;
 auto currRoot = currNode.first;
 if(currRoot->left != nullptr) nodeStack.push({currRoot->left,currNode.second+1});
 if(currRoot->right != nullptr) nodeStack.push({currRoot->right,currNode.second+1});
}
 
  return sum;
}
