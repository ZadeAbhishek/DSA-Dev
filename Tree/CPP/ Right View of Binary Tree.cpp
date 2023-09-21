/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    
    void traverse(Node* root, int level,map<int,int> &hash){
      
      // base
      if(root == NULL) return;
      
      // check if level already present
      if(hash.find(level) == hash.end()) hash.insert({level,root->data});
      
      traverse(root->right,level+1,hash);
      
      traverse(root->left,level+1,hash);
      
      return;
}
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       // Your code here
   
   // hash to store level wise order
   map<int,int> hash;
   
   traverse(root,0,hash);
   
   vector<int> ans;
   
   for(auto &x : hash) ans.push_back(x.second);
   
   return ans;
    }
};