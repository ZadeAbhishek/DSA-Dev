/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear
exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findNo(vector<int> &nums){
    long long result = 0;
    for(auto x : nums) result ^= x;
    long long mask = (result & ~(result - 1));
    int x = 0;
    int y = 0;
    for(auto no : nums) if((no&mask)>0) x^=no;
    y = result ^ x;
    return vector<int>{x,y}; 

}

// Tc = O(n) + O(n)

int main(){
    vector<int> nums{1,1,2,5,3,2,3,4,7,4};
    vector<int> res = findNo(nums);
    cout<<res[0]<<" "<<res[1]<<"\n";
}