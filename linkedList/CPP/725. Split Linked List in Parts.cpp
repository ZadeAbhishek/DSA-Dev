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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;  // Initialize the result vector to store the split lists.
        int list_size = 0;  // Initialize a variable to store the size of the input list.
        
        // Calculate the length of the input list.
        ListNode* ptr = head;
        while (ptr != NULL) {
            list_size++;  // Increment the list size for each node.
            ptr = ptr->next;  // Move to the next node.
        }

        // Check if it's possible to divide the list into k parts with at least one node in each part.
        int window = list_size / k;
        list_size = (window == 0) ? (list_size + (k - list_size)) : list_size;

        // Break the input list into k parts according to the specified size.
        auto i = head;
        while (list_size) {
            // Calculate the size of the current window for the current part.
            float s1 = static_cast<float>(list_size) / static_cast<float>(k);
            int currWindow = ceil(s1);
            
            // Push the current part's head into the result vector.
            result.push_back((i == NULL) ? NULL : i);
            currWindow--;  // Decrement the current window size.
            int count = 1;  // Initialize a count for nodes in the current part.

            // Traverse the input list to form the current part.
            while (i != NULL && currWindow--) {
                i = i->next;  // Move to the next node.
                count++;  // Increment the node count.
            }

            // If there are more nodes in the input list, detach them.
            if (i != NULL) {
                auto temp = i->next;  // Temporarily store the next node.
                i->next = NULL;  // Detach the current node.
                i = temp;  // Move to the next node.
            }

            list_size -= count;  // Decrement the remaining list size.
            k--;  // Decrement the remaining number of parts to create.
        }
        
        return result;  // Return the vector of split lists.
    }
};