//brute force approch
/**
 * " 3+5 / 2 " = 4
 * Input: s = "3+2*2"
Output: 7
*/
class Solution {
    stack<int> res_stack;
    long curr_res = 0;
    char sign = '+';
public:

int calculate(string t) {
     
     for(int i = 0 ; i < t.size() ; i++){
         if(isdigit(t[i])) curr_res = 10*curr_res + int(t[i] - '0');
         
        if(!isdigit(t[i]) && t[i] != ' ' || i == t.size()-1){
              
              if(sign == '+') res_stack.push(curr_res);
              else if(sign == '-') res_stack.push(-curr_res);
              else {
                  int num;
                  if(sign == '*') num = res_stack.top() * curr_res;
                  else if(sign == '/') num = res_stack.top() / curr_res;
                  res_stack.pop();
                  res_stack.push(num);
              }
              sign = t[i];
              curr_res = 0;
        }
     }
      int curr_sum  = 0;
        while(!res_stack.empty()) curr_sum += res_stack.top(),res_stack.pop();
        return curr_sum;
      

    }
};