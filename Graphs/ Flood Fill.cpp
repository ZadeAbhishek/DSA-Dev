class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color,int curr) {
        // consider if 1 is color we have given to change it to 2  or vise versa
        //cout<<sr<<" "<<sc<<"\n"
        
        if(!(sr<0 || sc <0 || sr > size(image)-1 || sr > size(image)-1)){
            
        if(image[sr][sc] == color) return image;  
        
        if(image[sr][sc] == curr)
        {
            image[sr][sc] = color;
            floodFill(image,sr,sc+1,color,curr);
            floodFill(image,sr+1,sc,color,curr);
            floodFill(image,sr-1,sc,color,curr);
            floodFill(image,sr,sc-1,color,curr);
            
        }
        }
        
        return image;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        return floodFill(image,sr,sc,color,image[sr][sc]);
    }
};