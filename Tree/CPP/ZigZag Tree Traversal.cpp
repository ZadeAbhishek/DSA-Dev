
// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include<bits/stdc++.h>
using namespace std;

int main(){}

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        if(root == NULL)  return {};
        
    	// queue
    	queue<Node*> q;
    	
    	q.push(root);
    	
    	int toggle = 1; // if 1 l - > r  0 r -> l
    	
    	vector<int> result;
    
    	
    	while(!q.empty()){
    	    
    	    int qSiz = q.size();
    	    
    	    vector<int> temp(qSiz,0);
    	    
    	    for(int i = 0 ; i < qSiz ; i++){
    	     
    	        // if 0 store in reverse order
    	        
    	        int index = (toggle)?i:qSiz-i-1;
    	        
    	        // top of q
    	        Node* curr = q.front();
    	        q.pop();
    	       
    	        // push current data in temp according toggle and order
    	        temp[index] = curr->data;
    	        
    	        
    	        // push next level
    	        if(curr->left != NULL) q.push(curr->left);
    	        
    	        if(curr->right != NULL) q.push(curr->right);
    	        
    	        
    	     }
    	     
    	     // toggle switch
    	     toggle = 1 - toggle;
    	     
    	     for(int x : temp) result.push_back(x);
    	    
    	 }
    	 return result;
    }
};