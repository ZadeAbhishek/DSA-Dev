class Solution {
public:
    
    
    
    int maxPoints(vector<vector<int>>& points) {
        
        if(size(points)<=2) return size(points);
        // idea is to itterate coordinate 
        // select corrdinate each corrdinate has three direction in which it straight line exists
        // calcuate scope for three direction
        int total = 0;
        for(auto& it : points)
        {
            // coordinates
            int xX = it[0];
            int yX = it[1];
            
            //direction

            //straight direction

            // int x1 = x;
            // int y1 = y + 1;

            // // upwared direction 
            // int x2 = x+1;
            // int y2 = y;

            // digonal
            //diagonal reverse
            // digonal
            // int x5 = x + 1;
            // int y5 = y - 1;
            // // digonal
            // int x6 = x - 1;
            // int y6 = y + 1;
            // // digonal
            // int x7 = x - 1;
            // int y7 = y - 1;



            int diagonal = 0;
           // cout<<"X:"<<x<<" "<<"Y:"<<y<<"\n";
             for(auto &yt : points)
             {
                  int xY = yt[0];
                 int yY = yt[1];
                 diagonal = 0;
                 for(auto &zt : points)
                 {
                      if(it != yt && zt != yt) {
                      int xZ = zt[0];
                      int yZ = zt[1];
                       if((xY-xX)*(yZ-yX) == (yY-yX)*(xZ-xX)) diagonal++;
                      }

                 }
                //  cout<<"x4:"<<x4<<" "<<"y4:"<<y4<<"\n";
                //  cout<<"S_x:"<<straight_x<<" "<<"S_y:"<<straight_y<<" "<<"Daigonal:"<<diagonal<<"\n";
                total = max(total,diagonal);
             cout<<"Total:"<<total<<"\n";
             }
             
        }
        return total+1;
    }
};