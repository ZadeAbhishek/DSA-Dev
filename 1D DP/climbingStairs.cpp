#include<bits/stdc++.h>
using namespace std;

class Solution {
 unordered_map<int,int> table;
 int count = 0;
 void climb(int n , int r){
   if(n == r) {
    count++;
    return;
   }
   if(r > n) return;
        for(int i = 1 ; i <= 2 ; i++){
           r += i;
           if(!table.count(r)){
           cout<<r<<" "<<i<<'\n';
           climb(n,r);
           table.insert({r,count});
           r -= i;
           }
           else{
            count += table[r]; 
           } 
        }
    return;    
 }
public:
    int climbStairs(int n) {
        // recursion and back trackng problem
        int res = 0;
        climb(n,res);
        return count;
    }
};

int main (){
  cout<<"Enter level";
  int i = 0;
  cin>>i;
  Solution *solve = new Solution();
  cout<<solve->climbStairs(i);
}