#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class EdgeNode{
    public:
    int adj;   // Number of adjecent nodes 
    int weight; // weight of edges
    EdgeNode *next; // next edges in list
};

class Graph{
   public:
   vector<EdgeNode*> edges;  // adjecent information
   vector<int> degree;   // outdegree of each vertices
   int nvertices;   // number of vertices
   int directed;    // is it directed or not

   Graph(int n){
     int i = 0;
     while(i <= n){
        EdgeNode* edge = new EdgeNode();
        edges.push_back(edge);
        degree.push_back(0);
        i++;
     }
     nvertices = n;
   } 

};


class MST{
    public:
    int Prims(Graph *g,int start){
        int i;                             // counter
        EdgeNode *p;                       // pointer
        bool intree[g->nvertices+1] = {false};       // To check if vertex is in tree or not
        int distance[g->nvertices+1] = {INT_MAX};      // cost of adding to tree
        int parent[g->nvertices+1] = {-1} ;        // parent of curr
        int curr;                          // cur vertex
        int next;                          // next to curr
        int wieght;                        // weight of edge
        int dist;                      // best distanve
        for(int j = 0 ; j < g->nvertices+1 ; j++){
            intree[j] = false;
            distance[j] = INT_MAX;
            parent[j] = -1;
        }
        distance[start] = 0;
        curr = start;
        while(intree[curr] == false){
            intree[curr] = true;
            p = g->edges[curr];
            
            while(p!=NULL){
                next = p->adj;
                wieght = p->weight;
                if((distance[next]>wieght) && (intree[next] == false) ){
                    distance[next] = wieght;
                    parent[next] = curr; 
                }
                p = p->next;
            }
            curr = 1;
            dist = INT_MAX;
            for(i = 1; i <=g->nvertices; i++ ){
                if((intree[i]==false) && (dist > distance[i])){
                    dist = distance[i];
                    curr = i;
                    //cout<<"Dist:"<<dist<<endl;
                }
            }
        }
        int result = 0;
        for(int k = 0; k < g->nvertices; k++ ){
            result += distance[k];
        }
     return  result;
    }
};

void insert(Graph *g, int x, int y, int weight,bool directed){
    EdgeNode* edge = new EdgeNode();
    edge->weight = weight;
    edge->adj = y;
    edge->next = g->edges[x];
    g->edges[x] = edge;
    g->degree[x]++;
    if(!directed){
        insert(g,y,x,weight,true);
    }

}

int main(){
    Graph *g = new Graph(4);
    insert(g,0,1,1,false);
    insert(g,1,2,2,false);
    insert(g,2,3,5,false);
    insert(g,3,0,4,false);
    insert(g,2,0,3,false);
    MST* mst = new MST();

    int result = mst->Prims(g,0);
    cout<<result<<endl; 
   
}