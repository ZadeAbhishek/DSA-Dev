class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int index = 0;
        vector<string> list(numRows);
        int flag = false;
        for(auto letter : s){
            list[index] += letter;
            if(index == 0 || index == numRows-1) flag = !flag;
            
            if(flag) index++;
            else  index--;
        }

        s = "";
        for(auto x :list){
            s+=x;
        }
        return s;
    }
};


/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"


*/