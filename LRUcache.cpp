#include<iostream>
#include<map>
using namespace std;
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
    class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int data,int k){
        this->key = k;
        this->val = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
    map<int,Node*>table;
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(table.count(key)!=0){
            remove(table[key]);
            add(table[key]);
            }
        else
        {
            return -1;
        }    
        return table[key]->val;
    }
    
    void put(int key, int value) {
        // Check if the key is present in the Hash
        if(table.count(key)!=0){
            //Just  update linkedList
                remove(table[key]);
                add(table[key]);
                table[key]->val = value; 
         
        }
        else{
            Node* ptr = tail->prev;
            if(table.size()==cap){
                table.erase(tail->prev->key);
                remove(tail->prev);
                table.insert({key,ptr});
                ptr->key = key;
                ptr->val = value;
                add(ptr);
            }
            else{
                Node* node = new Node(value,key);
                table.insert({key,node});
                add(node);
            }
        }
    }
    void remove(Node* &node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void add(Node* &node){
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
};

int main(){

    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 0); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache->get(1);    // return 1 
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4);
    lRUCache->put(3, 3); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lRUCache->get(1);    // return -1 (not found)
    cout<<lRUCache->get(3);    // return 3
    cout<<lRUCache->get(4);    // return 4
    return 0;
}