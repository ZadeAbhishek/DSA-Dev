// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

void operator<< (std::ostream &Cout , std::vector<int> x){
    for(auto i : x) Cout<<i<<" ";
    cout<<"\n";
    return;
}
// Brute Force
int largestRectangleArea(vector<int>& heights) {
        int max_area = INT_MIN;
        for(auto outer = 0 ; outer < heights.size() ; outer++){
            int i = outer+1;
            while(i < heights.size() && heights[outer] < heights[i]) i++;
            signed int j = outer-1;
            while(j > 0 && heights[outer] < heights[j]) j--;
            int width = i - j - 1;
            int area = width * heights[outer];
            max_area = max(max_area,area);

        }
        return max_area;
    }

// Optimal Solution 2 pass solution
vector<int> prevsmallest(vector<int> &heights){
        vector<int> ans(heights.size(),0);
        stack<int> s;
        s.push(-1);
        for(int x = 0 ; x < heights.size() ; x++){
            while(s.top()!= -1 && heights[x] <= heights[s.top()]) s.pop();
            ans[x] = s.top();
            s.push(x);
        }
        return ans;
    }

     vector<int> nextsmallest(vector<int> &heights){
        vector<int> ans(heights.size(),0);
        stack<int> s;
        s.push(-1);
        for(signed int x = heights.size()-1 ; x >= 0 ; x--){
            while(s.top()!= -1 && heights[x] <= heights[s.top()]) s.pop();
            ans[x] = s.top();
            s.push(x);
        }
        return ans;
    }
 
 
    int largestRectangleAreaOptimal(vector<int>& heights) {
        vector<int> nextsmall = nextsmallest(heights);
        vector<int> prevsmall = prevsmallest(heights);
        // cout<<nextsmall;
        // cout<<prevsmall;
        int i = 0;
        int max_area = INT_MIN;
        while(i < heights.size()){
            if(nextsmall[i] == -1) nextsmall[i] = heights.size();
            int area = (nextsmall[i] - prevsmall[i] - 1) * heights[i];
            max_area = max(max_area,area);
            i++;
        }
        return max_area;
    }

// 1 pass  
int largestRectangleAreaOptimal1Pass(vector<int>& heights){
    stack<int> s;
    int uB = heights.size(); // upper Bound
    int max_Area = INT_MIN;
    for(int i = 0 ; i <= uB ; i++){
        while(!s.empty() && (i == uB || heights[s.top()] > heights[i])){
             int h = heights[s.top()]; // height
             s.pop();
             int w; // width
             if(s.empty()) w = i;
             else w = i - s.top() - 1;
             int area = h * w;
             max_Area = max(max_Area,area);
        }
        s.push(i);
    }
    return max_Area;
}

int main(){
    vector<int> arr;
    arr = {2,1,5,6,2,3};
    cout<<largestRectangleArea(arr)<<"\n";
    cout<<largestRectangleAreaOptimal(arr)<<"\n";
    cout<<largestRectangleAreaOptimal1Pass(arr)<<"\n";
    
}