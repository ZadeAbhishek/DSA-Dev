class Solution {
    unordered_map<string,string> emailsSet; // like parent
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // we can do this using union-find set-union
        unordered_map<string,string> emailToName;

        for(auto user : accounts){
            string name = user[0];
            for(auto i = 1 ; i < user.size(); i++){
                string email = user[i]; // email
                emailToName[email] = name;
                if (emailsSet.find(email) == emailsSet.end()) {
                    emailsSet[email] = email;  // Each email is its own parent
                }
                // check with previous emails if they donnot belong to same parent map them
                if(i > 1) mapEmailSet(user[i],user[i-1]);
            }
        }

        // store a set into set // or create uniq structure
        unordered_map<string,unordered_set<string>> unionEmail;
        for(auto emailSet : emailsSet){
            string email = emailSet.first;
            string root = findRoot(email);
            unionEmail[root].insert(email);
        }

        // generate result
        vector<vector<string>> result;
        for(auto unionSet : unionEmail){
            string rootEmail = unionSet.first;
            vector<string> temp(unionSet.second.begin(),unionSet.second.end());
            sort(temp.begin(),temp.end()); // for lexographical order
            string getUser = emailToName[rootEmail];
            temp.insert(temp.begin(),getUser);
            result.push_back(temp);
        }

        return result;
    }

    private:

    string findRoot(string email){
        if(emailsSet[email] != email) return emailsSet[email] = findRoot(emailsSet[email]);
        else return emailsSet[email];
    }
    void mapEmailSet(string email1, string email2){
        string root1 = findRoot(email1);
        string root2 = findRoot(email2);
        if(root1 != root2) emailsSet[root2] = root1;
        return;
    }
};