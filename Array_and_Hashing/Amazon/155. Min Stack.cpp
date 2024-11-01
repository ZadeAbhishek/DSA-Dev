class MinStack {
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }
        else if(minStack.top() >= val){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(!mainStack.empty()){
        int val = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && minStack.top() == val){
            minStack.pop();
        }
        }
    }
    
    int top() {
       
       return !mainStack.empty()?mainStack.top():0;
    }
    
    int getMin() {
       return !minStack.empty()?minStack.top():0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */