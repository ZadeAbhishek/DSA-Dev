class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // bfs should work here
        queue<int> rooms_to_visit;
        
        // lock buffer
        vector<int> lock(size(rooms),1);        
        
        // since i can visit only zero at start
        for(auto it : rooms[0]) rooms_to_visit.push(it);

        lock[0]  = 0;

        while(! rooms_to_visit.empty())
        {
           int key = rooms_to_visit.front();
           rooms_to_visit.pop();
           if(lock[key])
           { 
            lock[key] = 0;
           for(auto it : rooms[key]) rooms_to_visit.push(it);
           }
        } 

        for(auto it : lock) if(it == 1) return false;
        
        return true;    
    }
};