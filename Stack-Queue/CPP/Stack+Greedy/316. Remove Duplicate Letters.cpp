class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> last_ocurr;
        stack<char> stack;
        for(int i = 0 ; i < s.size() ; i++) last_ocurr[s[i]] = i;
        unordered_set<char> visited;
        for(int i = 0 ; i < s.size() ; i++){
            char curr = s[i];
            if(visited.find(curr) == visited.end()){
                // element is not present in visited check if we can add
                while(!stack.empty() && curr < stack.top() && i < last_ocurr[stack.top()]){
                    // this is will occruse again and is greated than curr element
                    visited.erase(stack.top());
                    stack.pop();
                }
                visited.insert(curr);
                stack.push(curr);
            }
        }
        string result = "";
        while(!stack.empty()) result = stack.top() + result, stack.pop();
        return result;
    }
};