/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
//##BinarySearch
private:
   TreeNode* traverse(vector<int> &list, int start, int end) {
        if(start > end) return NULL;
        if(start == end) return new TreeNode(list[start]);
        int mid = start + ( (end - start) / 2);
        TreeNode* root = new TreeNode(list[mid]);
        root->left = traverse(list,start,mid-1);
        root->right = traverse(list,mid+1,end);
        return root;
   }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // this is variation of binary search 
        vector<int> list;
        for(auto x = head; x != NULL ; x = x->next){
            list.push_back(x->val);
        }
        return traverse(list,0,list.size()-1);
    }

};