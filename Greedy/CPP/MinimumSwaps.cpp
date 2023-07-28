#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<int> problem = {1,2,7,4,3,6,5,9,8};

    // We have to sort using min swaps
    // this is known as greedy approch
    // Idea behind is 
    // frist sort
    // and then make them like problem 
    // this will give minimun 
    // there we can use hashmap or pair as data structres

    unordered_map<int,int> Index_Table;

    // we will store index of each element

    for(auto i = 0 ; i < size(problem) ; i++) Index_Table.insert({problem[i],i});

    // Sort the previos array

    sort(begin(problem),end(problem));

    // again loop through sort element
 
    int count = 0;
   
    for(auto i = 0 ; i < size(problem) ; i++)
    {
        if(Index_Table[problem[i]] == i) continue;

        // swap the element
        
        int temp = Index_Table[problem[i]];

        
        // swap previous with current index
        swap(problem[i],problem[temp]);

        count++; 
    }

    cout<<count;
}