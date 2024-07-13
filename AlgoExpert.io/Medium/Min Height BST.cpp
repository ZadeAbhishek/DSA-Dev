using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};


BST* constructBST(const vector<int>& array, int start, int end) {
  if (start > end) return nullptr;
  int mid = start + (end - start) / 2;
  BST* root = new BST(array[mid]);
  root->left = constructBST(array, start, mid - 1);
  root->right = constructBST(array, mid + 1, end);
  return root;
}

BST* minHeightBst(vector<int> array) {
  // Write your code here.
  sort(array.begin(),array.end());
  return constructBST(array,0,array.size()-1);
}
