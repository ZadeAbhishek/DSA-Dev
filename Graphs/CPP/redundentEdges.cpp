#include <iostream>

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    // For this we need set_union dataStucture
    class Set_Union{
        public:
        vector<int> parent;
        vector<int> size;
        int set_size;
        // Set_Union(int size){
        //      for(auto i = 0;i <= size ; i++){
        //      this->parent.push_back(i);
        //      this->size.push_back(i);
        // }
        //}
    };
    
    void set_union_init(Set_Union* &set,int n){
        for(auto i = 0;i < n+1 ; i++){
            set->parent.push_back(i);
            set->size.push_back(1);
        }
        set->set_size = n;
    }
    
    int find(Set_Union* &set, int x){
        if(set->parent[x] == x){
            return x;
        }
        else{
            return find(set,set->parent[x]);
        }    
    }
    
    bool union_sets(Set_Union* &set, int v1, int v2){
        int x1;
        int x2;
        x1 = find(set,v1);
        x2 = find(set,v2);
        if(x1 == x2){
            return true;
        }
        if(set->size[x1] >= set->size[x2]){
            set->size[x1] += set->size[x2];
            set->parent[x2] = x1;
        }
        else{
            set->size[x2] += set->size[x1];
            set->parent[x1] = x2;
        }
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //idea is to use set-Union
        // we are given pairs here [1,2] 1<-2 [1,3] 1<-3 
        // we will consider that incially the graph is having 1 compoent and we will keep merging it
        
        //create set_union variable
        Set_Union* set = new Set_Union();
        
        // init sets 
        set_union_init(set,edges.size());
        
        //start loop and start mapping the  graph if any two vertices is already connect in graph algo will
        // retun true
        
        vector<int> result;
        
        for(auto i = 0; i < edges.size(); i++){
            if(union_sets(set,edges[i][0],edges[i][1])){
                result.push_back(edges[i][0]);
                result.push_back(edges[i][1]);
                return result;
            }
        }
        return result;
    }
};

int main() {
  vector < vector< int > > set = {{1,2},{1,3},{2,3}}; // array to store visited nodes
  Solution * solve = new Solution();
  vector < int > result = solve -> findRedundantConnection(set);
  for (auto index = 0; index < result.size(); index++) {
    cout << result[index] << " ";
  }
  cout << endl;
}