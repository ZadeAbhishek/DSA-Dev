class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> hash;
        string curr = "";
        
        // Process each character in the paragraph
        for(auto& x : paragraph) {
            // If the character is alphabetic, add it to the current word (convert to lowercase)
            if(isalpha(x)) {
                curr += tolower(x);
            } 
            // If it's a non-alphabetic character, treat it as the end of a word
            else if (!curr.empty()) {
                // Add the current word to the map
                hash[curr]++;
                curr = "";
            }
        }
        
        // To handle the last word (if paragraph doesn't end with punctuation)
        if (!curr.empty()) {
            hash[curr]++;
        }
        
        // Convert banned list into a set for faster lookup
        unordered_set<string> ban(banned.begin(), banned.end());

        // Find the most frequent word that is not banned
        string result = "";
        int maxFreq = 0;
        for (auto& [word, count] : hash) {
            if (ban.find(word) == ban.end() && count > maxFreq) {
                maxFreq = count;
                result = word;
            }
        }

        return result;
    }
};