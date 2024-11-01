/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hash;
        for(Node* n = head ; n != NULL ; n=n->next){
             hash[n] = new Node(n->val);
        }
        for(Node* n = head ; n != NULL ; n=n->next){
                hash[n]->next = n->next != NULL?hash[n->next]:NULL;
                hash[n]->random = n->random == NULL?NULL:hash[n->random];
            
        }
        return hash[head];
    }
};