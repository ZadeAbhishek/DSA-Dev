class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // bfs we can use here
        if(image[sr][sc] == color) return image;
        queue<pair<pair<int,int>,int>> st;
        st.push({{sr,sc},image[sr][sc]});
        // direction 
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!st.empty()){
            int currX = st.front().first.first;
            int currY = st.front().first.second;
            int currColour = st.front().second;
            image[currX][currY] = color;
            st.pop();
            for(auto d : dir){
                int nextX = currX + d[0];
                int nextY = currY + d[1];
                if(nextX >= 0 && nextY >= 0 && nextX < image.size() && nextY <= image[nextX].size() && image[nextX][nextY] != color && image[nextX][nextY] == currColour){
                        st.push({{nextX,nextY},currColour});
                }
            }
        }
        return image;
    }
};