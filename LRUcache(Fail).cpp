// Fail code 
/*
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        this->val = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
map<int,Node*> table;
Node* head = NULL;
Node* tail = NULL;
public:
    LRUCache(int capacity) {
        Node* pre;
        Node* curr;
        Node* headNode = new Node(-1);
        curr = pre = headNode;
        head = headNode;
        int i = 1;
        while(i!=(capacity+1)){
         Node* newNode = new Node(i);
         curr = newNode;
         curr->prev = pre;
         pre->next = curr;
         curr->next = NULL;
         pre = curr;
         tail = pre;
         table.insert({i,newNode});
         i++;
        }
    }
    
    int get(int key) {
            if(table[key]){
            if(table[key]!=tail){
                Node* curr = table[key];
                if(curr->next!=NULL){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                return key;
                }
                else{
                curr->prev->next = NULL;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                return key;
                }
            }
                else{
                      Node* curr = tail;
            if(curr->next!=NULL){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
                else{
                curr->prev->next = NULL;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
                }
            }
        
        return -1;
    }
    
    void put(int key, int value) {
       if(table[key]){
           if(table[key] != tail){
                Node* curr = table[key];
                if(curr->next!=NULL){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
                else{
                curr->prev->next = NULL;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
           }
           else{
                Node* curr = tail;
            if(curr->next!=NULL){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
                else{
                curr->prev->next = NULL;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
           }
            }
        else
        {
            int val = tail->val;
            tail->val = value;
            table.erase(val);
            table.insert({key,tail});
            Node* curr = tail;
            if(curr->next!=NULL){
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
                else{
                curr->prev->next = NULL;
                tail=curr->prev;
                curr->prev = head;
                head->next->prev = curr;
                curr->next = head->next;
                head->next = curr;
                }
            
        }
        
    }
};
*/