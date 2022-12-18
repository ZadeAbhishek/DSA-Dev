class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         
       // accroding to my method 1 que and 1 stack is needed to implement this 

       // idea is stack will have icremented value and one stack with decreased value

       stack<pair<int,int>> inc;
       inc.push({size(temperatures)-1,temperatures[size(temperatures)-1]});
       temperatures[size(temperatures) - 1] = 0;
       pair<int,int> p;
       int x = size(temperatures) - 2;
       for(auto index = x ; index >= 0 ; index--)
       {
    
        p.first = index;
        p.second = temperatures[index];
        if(p.second >= inc.top().second) while(!inc.empty() && p.second >= inc.top().second) inc.pop();
        if(inc.empty()) inc.push(p),temperatures[index] = 0;
        else temperatures[index] = abs(inc.top().first - p.first),inc.push(p);         
        
       }
       return temperatures;
    }
};




/*

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

*/