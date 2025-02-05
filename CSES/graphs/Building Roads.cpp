    /*
    Time limit: 1.00 s
    Memory limit: 512 MB



    Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
    Your task is to find out the minimum number of roads required, and also determine which roads should be built.
    Input
    The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
    After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
    A road always connects two different cities, and there is at most one road between any two cities.
    Output
    First print an integer k: the number of required roads.
    Then, print k lines that describe the new roads. You can print any valid solution.
    Constraints

    1 \le n \le 10^5
    1 \le m \le 2 \cdot 10^5
    1 \le a,b \le n

    Example
    Input:
    4 2
    1 2
    3 4

    Output:
    1
    2 3
    */
    #include<bits/stdc++.h>
    using namespace std;

    // union Find Implementation
    class unionFind {
        vector<int> parents;
        vector<int> ranks;
        int nodes = 0;
        
        public:
        unionFind(int n){
            this->nodes = n;
            this->parents.resize(n+1,0);
            this->ranks.resize(n+1,1);
            for(int i = 1 ; i <= n ; i++){
                this->parents[i] = i;
            }
        }


        int find(int n){
            // n == node
            if(this->parents[n] == n) return n;
            else return this->parents[n] = find(parents[n]);
        }

        bool unionSet(int x, int y){
            int a = this->find(x);
            int b = this->find(y);
            if(a == b) return false;

            if(this->ranks[a] < this->ranks[b]){
                this->parents[a] = b;
                this->ranks[b] += this->ranks[a]; 
            }
            else {
                // wise versa
                this->parents[b] = a;
                this->ranks[a] += this->ranks[b];
            }
            return true;
        }
    };


    int main(){
    int cities = 0;
    int numRoads = 0;
    cin>>cities>>numRoads;
    unionFind* uf = new unionFind(cities);
    for(int i = 1 ; i <= numRoads; i++){
        int a = 0;
        int b = 0;
        cin>>a>>b;
        uf->unionSet(a,b);
    }
    
    // find out unique sets
    vector<int> uniqueSets;
    for(int i = 1 ; i <= cities ; i++){
        if(uf->find(i) == i){
            uniqueSets.push_back(i);
        }
    }

    int roadsTobuild = uniqueSets.size() - 1;
    cout<<roadsTobuild<<endl;
    for(int i = 1 ; i < uniqueSets.size(); i++){
        cout<<uniqueSets[i]<<" "<<uniqueSets[i-1]<<endl;
    }
    return 0;
    
    }