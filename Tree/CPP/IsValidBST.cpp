/*

// only logic written here

bool isValidBST(BinaryTreeNode<int> *root , int min , int max){
    
    // end of the leaf node 
    if(root == NULL) return true;

    // check if current root is in range
    if(root->data >= min && root->data <= max){
        
        int left = isValidBST(root->left,min,root->value);
        int right = isValidBST(root->right,root->value,max);

        return left && right; // check if both are valid bst  
    }
    else return false;
}

// complexity TC : O(n)
//            SC : O(1) + Auxilarry stack space O(h) where h is hieght of tree   

*/