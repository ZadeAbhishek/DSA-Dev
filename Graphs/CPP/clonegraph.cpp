#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
};
void printNode(Node* temp){
    cout<<"Value: "<<temp->val<<endl;
    int l = temp->neighbors.size();
    vector<Node*> tempVec = temp->neighbors;
    int i = 0;
    while(i!=l){
        cout<<tempVec[i]->val<<" ";
        i++;
    }
    cout<<endl;
}
void creategraph(unordered_map<int,Node*> &m,int value,vector<int> n){
      if(m.count(value)){
       for(int i = 0;i<n.size();i++){
           m[value]->neighbors.push_back(m[n[i]]);
       }
      }
}
void dfs(Node* node,vector<bool> &vis,unordered_map<int,Node*> &m){
     cout<<node->val<<endl; // print the visited
      vis[node->val] = true; // make curr node to be visited
      for(auto it: node->neighbors){ // range for loop
        if(!vis[it->val]){   // if adjecents are visited 
        dfs(m[it->val],vis,m); //call Dfd with not visited nodes
      }
      }  
     return;
}

// Optimised DFS solution 
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){return NULL;}
        // simple approch is to use dfs here
        unordered_map<Node*,Node*> Node_table;
        Node* result =  dfs(Node_table,node);
        return result;
    }
    Node* dfs(unordered_map<Node*,Node*> &Node_table,Node* node){
             if(Node_table.count(node)){ return Node_table[node];}
             Node* clone_Node = new Node();
             clone_Node->val = node->val;
             Node_table.insert({node,clone_Node});
             for(auto it: node->neighbors){
                clone_Node->neighbors.push_back(dfs(Node_table,it));
            }
            return Node_table[node];
    }
};


int main(){
    unordered_map<int,Node*> m; 
    int no_node = 4;
    auto i = 1;
    while(i!=no_node+1){
       Node* temp = new Node();
       temp->val = i;
       m.insert({i,temp});
       i++;
    }
    creategraph(m,1,{2,3});
    creategraph(m,2,{1,4});
    creategraph(m,3,{1,4});
    creategraph(m,4,{2,3});
    vector<bool> vis(no_node,false);
    //dfs(m[1],vis,m);
    Solution* slove = new Solution();
   Node* result = slove->cloneGraph(m[1]);
   dfs(result);
}