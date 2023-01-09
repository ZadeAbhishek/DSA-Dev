class Solution {
public:
    
    int minDeletionSize(vector<string>& strs) {
        
        int count = 0;
        
        for(auto i = 0 ;  i < size(strs[0]) ; i++)
        {
            for(auto j = 1 ; j < size(strs) ; j++)
            {
                if(strs[j-1][i] > strs[j][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};