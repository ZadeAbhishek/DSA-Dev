#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available; // min heap init
        
        for(int i=0; i<size(tasks); i++)
            tasks[i].push_back(i);   // here i am adding index at back in tasks
        
        sort(begin(tasks),end(tasks)); // sorting the task list accroding to starting time
        
        int task_index = 0; // pointer for tasks array
        long long time = 0; // time (clock)
        vector<int> answer; // array to store answer


        while(size(answer) < size(tasks))  // if all task are added then size of both tasks and answers are equal
        {
             // check if there is any element in heap if not add curr task time in time variable or else skip 
             
             if(available.empty() && task_index < size(tasks)) time = tasks[task_index][0];  

             
             // check if not empty pop the element in top add to answer queue and add time of pop task to curr time variable
             
             if(!available.empty())
             {
                 answer.push_back(available.top().second);
                 time += available.top().first;
                 available.pop();
             }

             // if curr task time is less than equal to curr time add to heap
             // while loop is used if time is same for two or more task otherwise it is used as IF 
             while(task_index < size(tasks)  && tasks[task_index][0] <= time){
                 pair<int,int> temp;
                 temp.first =  tasks[task_index][1];
                 temp.second = tasks[task_index][2];
                 available.push(temp);
                 task_index++;
             }

        }
        return answer; 
    }
};