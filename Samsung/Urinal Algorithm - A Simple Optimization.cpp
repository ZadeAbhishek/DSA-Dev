/*
Problem #3. It is a well-researched fact that men in a restroom generally prefer to maximize their 
distance from already occupied stalls, by occupying the middle of the longest sequence of unoccupied 
places. For example, consider the situation where ten stalls are empty.

i/p:
Example of the output for the number of stalls = 10

_ _ _ _ X _ _ _ _ _

_ _ _ _ X _ _ X _ _

_ X _ _ X _ _ X _ _

_ X _ _ X _ _ X X _

_ X _ _ X X _ X X _

_ X X _ X X _ X X _

_ X X _ X X _ X X X

_ X X _ X X X X X X

_ X X X X X X X X X

X X X X X X X X X X

*/

#include<bits/stdc++.h>
using namespace std;

struct half{
    int start;
    int end;
    int lenght;
};

struct comparator{
    bool operator()(half const &a , half const &b){
        // if both half is of same lenght return according there start point
        // if lenght is not same return greatest lenght

        if(a.lenght != b.lenght) return a.lenght < b.lenght;
        else return a.start < b.start;
    }
};

priority_queue<half, vector<half>, comparator> maxHeap;


int placeMen(int start , int end , int lineLenght){
    maxHeap.push({start,end,lineLenght});
    int line[lineLenght] = {0}; // initalised with 0 to present as '_'
    while(!maxHeap.empty()){
        half curr = maxHeap.top();
        maxHeap.pop();
        int currStart = curr.start;
        int currEnd = curr.end;
        int mid = (currStart + currEnd)/2;
        
        // first we will push right then left
        if(currEnd > mid) maxHeap.push({mid+1,currEnd,currEnd-mid});
        if(currStart < mid) maxHeap.push({currStart,mid-1,mid - currStart});

        line[mid-1] = 1;

        for(auto x : line){
            if(x == 1) cout<<" X ";
            else cout<<" _ ";
        }
        cout<<endl;
    }
    return 0;
}


int main(){
    int x;
    cin>>x;
    placeMen(0,x+1,x);
}