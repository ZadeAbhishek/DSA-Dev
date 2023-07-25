/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    
    
     int traverse(Node *root,vector<int> &inorder){
          
          // base case
          if(root == NULL) return -1;
          
          int left = traverse(root->left,inorder);
          
          
          inorder.push_back(root->data);
          
          int right = traverse(root->right,inorder);
          
          
          return 1;
          
          
     }
    
    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        traverse(root,inorder);
        return inorder[inorder.size() - K];
    }
};