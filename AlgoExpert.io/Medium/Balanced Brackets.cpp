#include <stack>
using namespace std;

bool balancedBrackets(string str) {
    stack<char> stk;

    for (int index = 0; index < str.size(); index++) {
        char current = str[index];
        if (current != '(' && current != ')' &&
            current != '[' && current != ']' &&
            current != '{' && current != '}') {
            continue;
        }

        if (current == '(' || current == '[' || current == '{') {
            stk.push(current);
        } else {
            if (!stk.empty()) {
                if (current == ')' && stk.top() == '(') stk.pop();
                else if (current == '}' && stk.top() == '{') stk.pop();
                else if (current == ']' && stk.top() == '[') stk.pop();
                else return false;
            } else {
                return false;
            }
        }
    }

    return stk.empty();
}