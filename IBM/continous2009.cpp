#include<bits/stdc++.h>
using namespace std;

#define MAX 100000


// sliding window approch
int maxele(vector<int> t){
    
    int max = INT_MIN;
    for(auto i : t){
        if(i > max) max = i;
    }
    return max;
}

int main (){
    vector<int> q = {1,2,3,4,6};
    unordered_map<int,int> hs;
    for(auto i = 0 ; i < MAX + 1 ; i++) hs.insert({i,0});
    for(auto i : q) hs[i]++;
    int missing = 0;
    int repeated = 0;
    int mini = INT_MAX;
     for(auto s : q) hs[s]++;
    
     for(auto s : q) 
     {
        for(auto x = s ; x < s+q.size() ; x++)
        {
            if(!hs.count(x))
            {
                missing++;
                continue;
            }
               if(hs[x] == 0){
                  missing++;
               }
               if(hs[x] > 1)
             {
                repeated = hs[x];
             }
            
        }
        int res = repeated + (missing - repeated);
        //cout<<res;
        mini = min(mini,res);
        missing = repeated = 0;
     }

      cout<<mini;

}