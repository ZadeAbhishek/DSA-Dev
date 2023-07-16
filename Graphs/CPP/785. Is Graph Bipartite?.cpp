/**
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two 
independent sets such that every edge connects a node in one and a node in the other.

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

*/

#include<bits/stdc++.h>
using namespace std;


class UnionSet{
    std::vector<int> parent; // keep track of parent
    std::vector<int> size;
    std::vector<int> distance;

    public:
    UnionSet(int);
    std::pair<int,int> find(int);
    void setUnion(int,int);
    void print();
    bool checkBipartile(std::vector<std::vector<int>> edges);
};

UnionSet::UnionSet(int size){
    this->parent.resize(size);
    this->size.resize(size);
    this->distance.resize(size);
    for(int i = 0 ; i < size ; i++){
        this->parent[i] = i;
        this->size[i] = 1;
    }
}

std::pair<int,int> UnionSet::find(int x){
    // base case
    if(this->parent[x] == x) return {x,0}; 
    std::pair<int,int> curr = find(this->parent[x]);
    this->parent[x] = curr.first;
    this->distance[x] = (this->distance[x] + curr.second)%2;
    return {this->parent[x],this->distance[x]};
}

void UnionSet::setUnion(int x, int y){
    std::pair<int,int> parentX = this->find(x);
    std::pair<int,int> parentY = this->find(y);
     if(parentX.first == parentY.first) return;
if(this->size[parentX.first] > this->size[parentY.first]){
        std::swap(parentX,parentY);
    }
    this->parent[parentX.first] = parentY.first;
    this->distance[parentX.first] = (1 + parentX.second + parentY.second)%2;
    this->size[parentY.first] += this->size[parentX.first];
    return;
}

void UnionSet::print(){
    for(auto x : this->distance) std::cout<<x<<" ";
    std::cout<<"\n";
}

bool UnionSet::checkBipartile(std::vector<std::vector<int>> graph){
    
    for(auto i = 0; i < graph.size() ; i++){
        for(auto j = 0; j < graph[i].size(); j++){
           auto curr = this->find(i);
           auto next = this->find(graph[i][j]);
           if(curr.second == next.second) return false;
        }
    }
     return true;
}



class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        UnionSet* s = new UnionSet(graph.size()+1);
    for(auto i = 0; i < graph.size() ; i++){
        for(auto j = 0; j < graph[i].size(); j++){
            s->setUnion(i,graph[i][j]);
        }
    }
    return s->checkBipartile(graph);
    }
};

int main(){}