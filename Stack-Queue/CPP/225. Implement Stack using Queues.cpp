#include <iostream>
#include <deque>

class MyStack {
    std::deque<int> que;

public:
    MyStack() {
        // Constructor: Initialize an empty stack using a deque.
    }
    
    void push(int x) {
        // Push an element onto the stack by adding it to the back of the deque.
        que.push_back(x);
    }
    
    int pop() {
        // Pop the top element from the stack if it's not empty.
        // This operation is O(1) time complexity since we are using a deque.
        int temp = -1;
        if (!que.empty()) {
            temp = que.back();
            que.pop_back();
        }
        return temp;
    }
    
    int top() {
        // Get the top element of the stack without removing it.
        return que.back();
    }
    
    bool empty() {
        // Check if the stack is empty by checking if the deque is empty.
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main() {
    // Create an instance of MyStack
    MyStack* obj = new MyStack();

    // Push some elements onto the stack
    obj->push(1);
    obj->push(2);
    obj->push(3);

    // Test pop and top operations
    std::cout << "Top element: " << obj->top() << std::endl; // Should print "Top element: 3"

    int param_2 = obj->pop(); // Pop the top element
    std::cout << "Popped element: " << param_2 << std::endl; // Should print "Popped element: 3"

    // Check if the stack is empty
    bool param_4 = obj->empty();
    std::cout << "Is stack empty? " << (param_4 ? "Yes" : "No") << std::endl; // Should print "Is stack empty? No"

    // Clean up memory by deleting the MyStack object
    delete obj;

    return 0;
}
