#include<iostream>
#include<vector>

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

bool UnionSet::checkBipartile(std::vector<std::vector<int>> edges){
    
    for(auto x: edges){
        auto curr = this->find(x[0]);
        auto next = this->find(x[1]);
        if(curr.second == next.second) return false;
        }
        return true;
}

int main(){
    std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,4}};
    int n = 4;
    UnionSet* s = new UnionSet(n+1);
    for(auto x : edges){
        s->setUnion(x[0],x[1]);
    }
    std::cout<<s->checkBipartile(edges)<<"\n";
    return 0;
    
    
}