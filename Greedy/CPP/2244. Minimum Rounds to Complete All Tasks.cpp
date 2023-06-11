class Solution {
public:
    
    // this approchh is very good

    //  int minimumRounds(vector<int>& tasks) {

    //     unordered_map<int,int> table;

    //     for(auto i : tasks) table[i]++; 

    //     int level = 0;
        
    //      for(auto &p : table)
    //     {
    //          int temp = p.second;   
    //          if(temp == 1) return -1;
    //          level += (p.second + 2)/3;
    //     }


    //     return level;

    // }



    int minimumRounds(vector<int>& tasks) {

        tasks.push_back(INT_MAX);
        sort(begin(tasks),end(tasks));

        int prev = tasks[0];
        
        int level = 0;

        int count = 1; 
        
        for(auto i = 1 ; i < size(tasks) ; i++)
        {
             //cout<<prev<<" "<<tasks[i]<<"\n";
             
             if(tasks[i] != prev) 
             {
                  if(count == 1) return  -1;

                //  cout<<count<<"\n";
                  
                  level += (count + 2) / 3;
                  
                  count = 1;

                  prev = tasks[i];

                  continue; 
             } 
             prev = tasks[i];
             count++;
        }


        return level;
    }
};