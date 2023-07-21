#include<bits/stdc++.h>
using namespace std;

inline int min_no(int x, int y){return (x>y)?y:x;}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<"Min no is:"<<min_no(x,y)<<"\n";
    return 0;
}