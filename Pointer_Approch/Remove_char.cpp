// Question is A string is given and cost array is given of length as same as string
// s = "ABBCDE" cost = {1,2,4,2,4,5}
// AIM is to remove duplicate(no two charector is consicative) at minimum cost;
// ABBCDE is BB cannot be toagther so remove
// ABCBDE this valid no need to remove

// Solution is to solve using pointer approch
#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>


int remove_Duplicate(std::string s, std::vector<int> &cost){
    // Pointer approch is used here
    int curr = 1;
    int prev = 0;
    int minCost = 0;
    while(curr <= s.size()-1){
        //check if the char are same get least cost
        if(s[prev] == s[curr]){
            int min = std::min(cost[prev],cost[curr]);
            minCost += min;
        }
        prev++,curr++;
    }
    return minCost;
}


int main(){
    std::vector<int> cost = {1,2,4,2,4,5,6};
    std::string s = "ABBCDEE";
    std::cout<<remove_Duplicate(s,cost)<<"\n";
}