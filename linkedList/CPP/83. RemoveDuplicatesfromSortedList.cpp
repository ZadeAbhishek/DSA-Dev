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

/*
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        ListNode* ptr = head;
        while(ptr != nullptr){
            if(ptr->val == prev->val) 
                  prev->next = ptr->next;
            else prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};

void operator<<(ostream &Cout , ListNode* head){
    while(head != NULL){
        Cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
    return;
}


int main(){
     int siz;
    cin>>siz;
    vector<ListNode*> temp(siz);
    temp[0] = new ListNode;
    cin>>temp[0]->val;
    for(int i = 1 ; i < siz ; i++){
        
        temp[i] = new ListNode;
        cin>>temp[i]->val;
        temp[i-1]->next = temp[i];
    }
    temp[siz-1]->next = NULL;
    cout<<temp[0];
    Solution *solve = new Solution();
    cout<<solve->deleteDuplicates(temp[0]);
}