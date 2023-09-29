class Solution {
public:
    
    int plus(stack<int> &bufferStack){
        int x = bufferStack.top();
        bufferStack.pop();
        int y = bufferStack.top();
        bufferStack.pop();
        return x+y;
    }

    int minus(stack<int> &bufferStack){
        int x = bufferStack.top();
        bufferStack.pop();
        int y = bufferStack.top();
        bufferStack.pop();
        return y-x;
    }

    int div(stack<int> &bufferStack){
        int x = bufferStack.top();
        bufferStack.pop();
        int y = bufferStack.top();
        bufferStack.pop();
        return (int)y/x;
    }

    int multiply(stack<int> &bufferStack){
        int x = bufferStack.top();
        bufferStack.pop();
        int y = bufferStack.top();
        bufferStack.pop();
        return x*y;
    }

 
    int evalRPN(vector<string>& tokens) {
        
        // so using stack we can solve this
        stack<int> bufferStack;
        // store elemet in stack until the any of this (+,-,/,*) is dicovered pop two element
        for(auto itretor : tokens)
        {
             // Do maths
           if(! bufferStack.empty() && bufferStack.top() >= 268435456) return 2147483648;
           if(itretor == "+") bufferStack.push(plus(bufferStack));
           else if(itretor == "-") bufferStack.push(minus(bufferStack));
           else if(itretor == "*") bufferStack.push(multiply(bufferStack));
           else if(itretor == "/") bufferStack.push(div(bufferStack));
           else bufferStack.push((int)stoi(itretor));
          // cout<<bufferStack.top()<<"\n"; 
            // repeat till end of array
        }
       return bufferStack.top();
       

      

    }
};



// improved version


  int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
                s.push(stoi(tokens[i]));
            else{
                int a=s.top();
                s.pop();
                if(tokens[i]=="+")
                    s.top()+=a;
                else if(tokens[i]=="-")
                    s.top()-=a;
                else if(tokens[i]=="*")
                    s.top()*=a;
                else if(tokens[i]=="/")
                    s.top()/=a;
            }
        }
        return s.top();
    }


    //ther is also recuursive solution