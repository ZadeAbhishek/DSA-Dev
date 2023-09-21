/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void traverse(Node* root, int level,map<int,int> &hash){
      
      // base
      if(root == NULL) return;
      
      // check if level already present
      if(hash.find(level) == hash.end()) hash.insert({level,root->data});
      
      traverse(root->left,level+1,hash);
      
      traverse(root->right,level+1,hash);
      
      return;
}


//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   
   // hash to store level wise order
   map<int,int> hash;
   
   traverse(root,0,hash);
   
   vector<int> ans;
   
   for(auto &x : hash) ans.push_back(x.second);
   
   return ans;
}