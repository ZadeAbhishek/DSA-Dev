class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // create hash use arry
        s.push_back(' '); // each  word is separated by space so last word is also add space
        
         // hash to track char to string
        vector<string> char_string_hash(128,"");
        
        // haash to track string to char
        unordered_map<string,char> hash_string_char; 
        
        // pointer to pattern array
        int pattern_ptr = 0; 
        
        // temp string varaiable to store curr string from s
        string temp = "";  

        // iterate over s
        for(auto it = 0 ; it < size(s) ; it++)
        {
            
            
            // else check
            if(s[it] == ' ')
            {
                
                // if word is not present in add to hash_string_char 
                // here string key and char is value
                if(!hash_string_char.count(temp)) hash_string_char.insert({temp,pattern[pattern_ptr]}); 
             
                // check if char is not present then add char and string
                /// here char is key and string is value
                if(char_string_hash[(int)pattern[pattern_ptr]] == "") char_string_hash[(int)pattern[pattern_ptr]] = temp;

                // if char is present check if they are same word as curr
                // if yes no problem continue
                // else return false
                else if (char_string_hash[(int)pattern[pattern_ptr]] != temp) return false;

                // if string is present check if char mapped to string is same as curr char
                // if yes no problem
                // else return false
                if(hash_string_char[temp] != pattern[pattern_ptr]) return false;
                
                
                // if everything is okay increment pattern ptr continue
                pattern_ptr++;
                temp = "";
                continue;
            }
             // if no space keep pushing char to temp string
            temp.push_back(s[it]);
        }
        // if size of pattern is large than s and word are correctly map then is migh create problem
        // so to check this we add this line
        if(pattern_ptr != size(pattern)) return false; 
        
        // everythinh good return true
        return true;
    }
};