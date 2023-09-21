#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> gp(vector<string> &vec,int open , int close, string temp){
        //base case
        if(open == 0 && close == 0){
            vec.push_back(temp);
            return vec;
        }

        if(open == close){
            // since we can only start with open parenthesis so this 
            gp(vec,open-1,close,temp+'('); 
        }
        else{
            if(open != 0) gp(vec,open-1,close,temp+'(');
            gp(vec,open,close-1,temp+')');
        }
        return vec;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string temp = "";
        // Recurrsion Dyanamic programming
        int openB = n;
        int closeB = n;
        return gp(vec,openB,closeB,temp);
    }
};

// optimised 76% faster
class Solution2
{
  vector<string> result;
  public:

    void getcombination(string &curr, int open, int close)
    {
     	// base case 
      if (open == 0 && close == 0)
      {
        result.push_back(curr);
        return;
      }

      if (open > close || open < 0 || close < 0) return;

      curr.push_back('(');
      getcombination(curr, open - 1, close);
      curr.pop_back();

      curr.push_back(')');
      getcombination(curr, open, close - 1);
      curr.pop_back();

      return;
    }

  vector<string> generateParenthesis(int n)
  {
    string temp = "";
    getcombination(temp, n, n);
    return result;
  }
};



int main(){}