/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // There are two things to do first we need to find the ID and and then get the sum
        unordered_map<int,Employee*> hash;
        for(auto x : employees){
            hash[x->id] = x;
        }
        
        if(hash.count(id)){
            
            queue<Employee*> qu;
            qu.push(hash[id]);
            int totalImportance = 0;
            while(!qu.empty()){
                auto start = qu.front();
                qu.pop();
                totalImportance += start->importance;
                for(auto x : start->subordinates) qu.push(hash[x]);
            }

            return totalImportance;
        }
        else return 0;
    }
};