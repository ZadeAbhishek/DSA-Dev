class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

bool validateBstHelper(BST* tree, int minValue, int maxValue) {
  if (tree == nullptr) return true;

  if (tree->value < minValue || tree->value >= maxValue) return false;

  return validateBstHelper(tree->left, minValue, tree->value) &&
         validateBstHelper(tree->right, tree->value, maxValue);
}

// Wrapper function to validate the BST
bool validateBst(BST* tree) {
  return validateBstHelper(tree, INT_MIN, INT_MAX);
}
