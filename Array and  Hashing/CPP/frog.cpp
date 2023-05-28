#include <bits/stdc++.h>

using namespace std;


int minJumps(int n , vector<int> a){
    unordered_set<int> buffer; // for values
    
    //buffer.insert(a[0] + 0);
    int count = 0;
    bool flag = false;
    for(auto j = 0 ; j < n ; j++)
    {
        if(j >= n) return count+1;
        if(a[j] == 1) {
            if(!flag) count++;
            flag = true;
            continue;
        }
        
        for(auto i = 1 ; i < a[j] ; i++){
        flag = false;
        //cout<<(buffer.find(a[j] + i) == buffer.end())<<"\n";
        if(buffer.find(a[j] + i) == buffer.end())
        {
          buffer.insert(a[j] + i);
          j = a[j] + i;
          count+=a[j];
          continue;
        }
       }
        
    }
    return count+1;
}

int main() {
    // Write C++ code here
    cout<<minJumps(5,{2,3,1,1,4});
    cout<<minJumps(5,{1,1,1,2,4});
    cout<<minJumps(3,{2,1,1});

    return 0;
}