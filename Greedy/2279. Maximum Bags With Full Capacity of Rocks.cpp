class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        // // idea is to use pair and stored in vector
        // pair<int,int> cap_rock;
        // vector<pair<int,int>> map;
        // for(auto index = 0 ; index < size(capacity) ; index++)
        // {
        //     cap_rock.first = capacity[index];
        //     cap_rock.second = rocks[index];
        //     map.push_back(cap_rock);
        // }
        // // sort vector 
        // sort(begin(map),end(map),greater<pair<int,int>>());
        
        // // fill vector till capacity
        // int counter = 0;
        // for(auto curr : map)
        // {
        //    cout<<curr.second<<" "<<curr.first<<"\n";
        //     while(curr.second < curr.first && additionalRocks > 0)
        //     {
        //          curr.second++;
        //          additionalRocks--;
        //     }
        //     if(curr.second == curr.first) counter++;

        //     if(additionalRocks == 0) break;
        // }

        // // calcaute total 
        // // return
        // return counter;


        // second logic 

        vector<int> remaining;
        int counter = 0;
        for(auto index = 0 ; index < size(capacity) ; index++)
        {
           if(capacity[index] > rocks[index])
           {
               remaining.push_back(capacity[index] - rocks[index]);
               continue;
           }
           counter++;
        }

        sort(begin(remaining),end(remaining));
        signed int temp = additionalRocks;
        for(auto curr : remaining)
        { 
            if(temp <= 0) return counter;
            temp -= curr;
            if(temp >= 0) counter++;
           
        
        }
        return counter;
    }
};