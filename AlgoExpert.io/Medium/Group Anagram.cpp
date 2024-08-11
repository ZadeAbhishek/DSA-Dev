#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  unordered_map<string,vector<string>> stringHash;
  for(auto str : words){
    string temp = str;
    sort(temp.begin(),temp.end());
    if(stringHash.count(temp)){
      stringHash[temp].push_back(str);
    }
    else{
      stringHash.insert({temp,{str}});
    }
  }
  vector<vector<string>> result;
  for(auto vectorString : stringHash){
    result.push_back(vectorString.second);
  }
  return result;
}
