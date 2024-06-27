#include <stack>
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
  stack<BST*> stk; // here we will store the nodes
  stk.push(tree);
  int closest = tree->value; 
  while(!stk.empty()){
   // check the conditions 
   BST* currNode = stk.top();
   stk.pop();

   // this logic is imp here 
   if(std::abs(target - closest) >  std::abs(target  - currNode->value)) closest = currNode->value;
   if(currNode->value < target && currNode->right != nullptr) stk.push(currNode->right);
   else if(currNode->value > target && currNode->left  != nullptr) stk.push(currNode->left);
  }
  return closest;
}
