#include<bits/stdc++.h>

using namespace std;

// struct Node{
//     int val;
//     int key;
//     Node* next = NULL;
//     Node(int key, int val):val(val),key(key),next(NULL){}
// };

// // works partially
// class MyHashMap {

//     vector<Node*> table;
//     int size = 769;

// public:

//     MyHashMap(){
//         table.resize(size);
//     }

//     int hashFunction(int key){
//         // good prime number
//         return (key % size);
//     }

//     void put(int key, int value) {

//         // we are going to use chaining method

//         // get index using hash function
//         int index = hashFunction(key);

//         //check if the index is pointer is null or not
//         if(table[index] == NULL) {
//             table[index] = new Node(key,value);
//             return;
//         }

//         // if not null check if already present
//         Node* i;
//         for(i = table[index] ; i != NULL ; i = i->next){
//             if(i->key == key){
//                 i->val = value;
//                 return;
//             }
//             if(i->next == NULL) break;
//         }
//      i->next = new Node(key,value);

//      return;
//     }

//     int get(int key) {

//        // get index
//        int index = hashFunction(key);

//        //loop
//        for(Node* i = table[index] ; i != NULL ; i = i->next){
//          if(i->key == key) return i->val;
//        }
//        return -1;
//     }

//     void remove(int key) {

//         // get index
//         int index = hashFunction(key);

//         Node* i = table[index];
//         Node* parent = table[index];
//         for(;i != NULL ; i = i->next){
//             if(i->key == key) break;
//             parent = i;
//         }

//         if(i == NULL) return; 

//         // check start
//         if(parent == i)  table[index] = NULL;
//         else parent->next = i->next;

//         return;

//     }
// };

// implemetation using lists

class MyHashMap {

   vector < list < pair < int, int >>> table;
   int size = 769;

   public:

      MyHashMap() {
         table.resize(size);
      }

   int hashFunction(int key) {
      // good prime number
      return (key % size);
   }

   void put(int key, int value) {

      // we are going to use chaining method

      // get index using hash function
      int index = hashFunction(key);

      //check if the index is pointer is null or not
      auto & chain = table[index];

      for (auto & curr: chain) {
         if (curr.first == key) {
            curr.second = value;
            return;
         }
      }
      chain.push_back({
         key,
         value
      });
      return;
   }

   int get(int key) {

      // get index
      int index = hashFunction(key);

      // loop
      auto & chain = table[index];

      for (auto curr: chain) {
         if (curr.first == key) return curr.second;
      }

      return -1;
   }

   void remove(int key) {

      // get index
      int index = hashFunction(key);

      // find
      auto & chain = table[index];

      for (auto curr: chain) {
         if (curr.first == key) {
            chain.remove(curr);
            return;
         }
      }
   }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
   MyHashMap myHashMap;
   myHashMap.put(1, 1); // The map is now [[1,1]]
   myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
   cout << myHashMap.get(1) << "\n"; // return 1, The map is now [[1,1], [2,2]]
   cout << myHashMap.get(3) << "\n"; // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
   myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
   cout << myHashMap.get(2) << "\n"; // return 1, The map is now [[1,1], [2,1]]
   myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
   cout << myHashMap.get(2) << "\n"; // return -1 (i.e., not found), The map is now [[1,1]]
}