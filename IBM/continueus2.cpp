#include<bits/stdc++.h>
using namespace std;

const int N = (1e5 + 10); 

vector<int> hs(N,0);

void create_Hash(vector<int> arr){

    // basically implementig counting sort

    for(auto s : arr) hs[s]++;

    return ;

}


int get_max(vector<int> arr)
{
    int m = 0;
    for(auto x : arr) m = x>m?x:m;
    return m;
}

int duplicate(int max)
{
    vector<int> replace;
    for(auto i = 0 ; i < max ; i++)
    {
        while(hs[i] > 1)
        {
               replace.push_back(i);
               hs[i]--;
        }
    }

    for(auto x : replace)
    {
        for(auto y = 0 ; y <= size(hs); y++)
        {
            if(y > x && hs[y] == 0){
               hs[y] = 1;
               break;
            }
        }
        
    }
    return size(replace);
}

int check(int min, int size)
{
    int count = 0;
    for(auto x = min ; x < (min+size) ; x++)
    {
        if(hs[x] == 0) count++;
    }
    return count;
}
int main (){
    
    vector<int> q = {1,2,3,5,6};
    
    create_Hash(q);
     
    int max = get_max(q);

    // check for duplicates

    int duplicates = duplicate(max);

    // check for missing 
    
    int missing = INT_MAX;
    
    for(auto x : q)
    {
       missing = min(missing,check(x,size(q)));
    }

    // for( auto x = 0 ; x < 100 ; x++)
    // {
    //     cout<<hs[x];
    // }
    cout<<missing+duplicates;
    return missing+duplicates;
}