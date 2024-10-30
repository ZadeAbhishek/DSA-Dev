class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Basic sorting Quesitons
        vector<pair<string,string>> letters;
        vector<pair<string,string>> numbers;
        int n = logs.size();

        for(auto log : logs){
            int i = 0;
            string key = "";
            // get key
            while(log[i] != ' ') key += log[i],i++;
            i++;
            // check for number of letter
            int checkForNumber = 0; // assumtion string is not number
            int logSize = log.size();
            string currString = ""; 
            while(i < logSize){
                if(log[i] >= '0' && log[i] <= '9') checkForNumber = 1;
                currString += log[i];
                i++;
            }
            if(checkForNumber == 1) numbers.push_back({key,currString});
            else  letters.push_back({key,currString});
        }

        // sort the letter string
        sort(letters.begin(),letters.end(),[](pair<string,string> a,pair<string,string> b){
               if(a.second == b.second) return a.first < b.first;
               return a.second < b.second;
        });

        // merging the string
        vector<string> ans;

        for(int i = 0; i < letters.size(); i++){
            string s = letters[i].first + " " + letters[i].second;
            ans.push_back(s);
        }

        for(int i = 0; i < numbers.size(); i++){
            string s = numbers[i].first + " " + numbers[i].second;
            ans.push_back(s);
        }
        
        
        return ans;
    }
};