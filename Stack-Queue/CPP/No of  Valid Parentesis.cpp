class Solution {
public:
     

    bool isValid(char t,char s) {
        if(t == '{' && s == '}') return true;
        else if(t == '(' && s == ')') return true;
        else if(t == '[' && s == ']') return true;
        else return false;

    } 


    int getValidityCount(string &s, int start , int end){
        // base case 
        if(start > end) return 0;
        
        // Solver
        int maxCount = 0;
        for(int curr = start ; curr < end ; curr++){
            int currMax = 0;
            if(!isValid(s[curr],s[end])) currMax = 0 + getValidityCount(s,start,curr-1) + getValidityCount(s,curr+1,end-1);
            else currMax = 2 + getValidityCount(s,start,curr-1) + getValidityCount(s,curr+1,end-1);

            maxCount = max(maxCount,currMax); 
        }
        return maxCount; 
        
    }

    int longestValidParentheses(string s) {
        // Partition DP
        int string_Lenght = s.size();
        s.push_back('#');
        s.insert(s.begin(),'#');
        return getValidityCount(s,1,string_Lenght);
    }
};