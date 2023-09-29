#include<bits/stdc++.h>
using namespace std;

/*

Kruskal Algorithm
1. sort edges according min weight
2. start creating graph and check if cycle in present or not
3. if yes dint add move on
4. if no add to result 
5. print result

*/


struct edge{
    int s;  // sourse
    int d;  // destination
    int w;  // weight
    edge(int S, int D, int W){
        s = S;
        d = D;
        w = W;
    }
};

void operator<< (ostream &Cout , vector<edge> e){
    for(auto x : e){
        Cout<<x.s<<" "<<x.d<<" "<<x.w<<"\n";
    }
}



bool cmt(edge x, edge y){
  return x.w < y.w;
}


class setUnion{
    vector<int> parent;
    vector<int> size;
    int set_size;
    public:
    setUnion(int s){
        // s = size
        for(auto x = 0 ; x < s ; x++) parent.push_back(x),size.push_back(1);
        set_size = s;
    }
    
    int find(int x){
       // base 
       if(parent[x] == x) return x;
       else return find(parent[x]);
    }

    bool Union(edge e){
        int x = find(e.s);
        int y = find(e.d);
        if(x == y) return true;

        if(size[x] >= size[y]) size[x] += size[y],parent[y] = x;
        else size[y] += size[x],parent[x] = y;
        return false; 
    }
};

int main(){
  vector<edge> edges;
  edges.push_back(edge(5,4,9));
  edges.push_back(edge(5,1,4));
  edges.push_back(edge(1,4,1));
  edges.push_back(edge(4,2,3));
  edges.push_back(edge(2,3,3));
  edges.push_back(edge(4,3,5));
  edges.push_back(edge(1,2,2));
  edges.push_back(edge(3,6,8));
  edges.push_back(edge(6,2,7));

  sort(edges.begin(),edges.end(),cmt); // sort

  vector<edge> result;

  setUnion* s = new setUnion(7);
  
  for(auto x : edges) if(!s->Union(x)) result.push_back(x);

  cout<<result;



}