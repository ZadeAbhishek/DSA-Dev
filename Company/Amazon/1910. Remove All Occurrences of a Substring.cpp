class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s == "") return s;
        // we can solve this recurrsively with Sliding window
        // or we can solve this itteritively
        int lenghtOfPart = part.size();
        int start = 0;
        int index = 0;
        int occured = 0;
        string result = "";
        string tempS = "";
        while(index <= s.size()){
            tempS += s[index];
            if(tempS.size() == lenghtOfPart){
                if(tempS == part){
                    // concatinate part one
                    for(int i = 0; i < start ; i++){
                        result += s[i];
                    }
                    for(int i = index + 1; i < s.size() ; i++){
                        result += s[i];
                    }
                    result = removeOccurrences(result,part);
                    occured = 1;
                    break;
                }
                else {
                    string newTempS = "";
                    for(int i = 1 ; i < tempS.size() ; i++){
                        newTempS += tempS[i];
                    }
                    tempS = newTempS;
                    start++;
                }
            }
            index++;
        }
        if(occured) return result;
        else return s;
    }
};



// if finf founds part in s it return starting index of it else it will return npos
class Solution {
public:
    string removeOccurrences(string s, string part) {

        // if lenght is greater than zero check for string erase it and check again till no match is found
        while(s.length() > 0 && s.find(part) != string::npos){
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};