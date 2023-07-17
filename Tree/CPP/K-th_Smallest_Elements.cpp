/*
// property of BST inorder Traverasal of BST gives Sorted elements from smallest to largest

// only logic is written here
// step 1 : Initialize counter
// step 2 : start travesing inorder left --> root --> right
// Increment count when you go from left-->root
// if count is equal to K return root->value else return -1; 
 
int kthSmallestElement(Bst<int*> root , int &i, int K){

    
    if(root == NULL) return -1; // no tree further;

    // we are going inorder left -> root -> right so we need to check first left

    int left = kthSmallestElement(root->left,i,k);

    //check if left is  -1 or not because if -1 tree doesnot exisit and curr root is node

    if(left != -1){
        // this means we have ans
        return left;
    }

    // increment count
    i++;

    if(i == k) return root->value;

    // return the last option

    return kthSmallestElement(root->right, i, k);
    
}


// to find the largest elment we just need to consider index = (n-k)+1 // for example to find 3 larget WITH 8 total nodes 8-3+1=6 last 6th node is the largest 3rd node;

*/