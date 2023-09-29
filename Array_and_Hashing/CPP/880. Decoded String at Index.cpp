class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // we design direct string here
        string tape = "";
        for(auto &curr : s){
            if(curr - 'a' >= 0 && curr - 'a' <= 27) tape += curr;
            else{
                int repeat = curr - '0';
                repeat -= 1;
                string temp = tape;
                while(repeat) tape+= temp, repeat--;
            }
        }
        string result = "";
        result += tape[k-1];
        return result;
    }
};


class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // we design direct string here
        string tape = "";
        for(auto &curr : s){
            if(curr - 'a' >= 0 && curr - 'a' <= 27) tape += curr;
            else{
                int repeat = curr - '0';
                repeat -= 1;
                string temp = tape;
                while(repeat) tape+= temp, repeat--;
            }
        }
        string result = "";
        result += tape[k-1];
        return result;
    }
};