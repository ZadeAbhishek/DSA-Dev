#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class stackElement {
public:
    int value;
    int min = INT_MAX;
    int max = INT_MIN;
};

class MinMaxStack {
    vector<stackElement*> stack;

public:
    int peek() {
        if (stack.empty()) return 0;
        return stack.back()->value;
    }

    int pop() {
        if (stack.empty()) return 0;
        int peekValue = peek();
        stack.pop_back();
        return peekValue;
    }

    void push(int number) {
        stackElement *temp = new stackElement();
        temp->value = number;
        if (stack.empty()) {
            temp->min = number;
            temp->max = number;
        } else {
            stackElement *peek = stack.back();
            temp->min = std::min(peek->min, number);
            temp->max = std::max(peek->max, number);
        }
        stack.push_back(temp);
    }

    int getMin() {
        if (stack.empty()) return 0;
        return stack.back()->min;
    }

    int getMax() {
        if (stack.empty()) return 0;
        return stack.back()->max;
    }
};