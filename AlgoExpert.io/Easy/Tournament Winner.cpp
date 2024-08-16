#include <vector>
using namespace std;

string tournamentWinner(
  vector<vector<string>> competitions, vector<int> results
) {
  // Write your code here.
  // we can use hashmaps here
  unordered_map<string,int> hash;
  for(auto x : competitions){
    auto teamA = x[0];
    auto teamB = x[1];
    if(!hash.count(teamA)) hash.insert({teamA,0});
    if(!hash.count(teamB)) hash.insert({teamB,0});
  }
  
  for(int i = 0 ; i < results.size(); i++){
      if(results[i] == 1){
        hash[competitions[i][0]]++;
      }
    else hash[competitions[i][1]]++;
  }

  string resultString = "";
  int maxCount = INT_MIN;


  for(auto x : hash){
     if(maxCount < x.second){
       resultString = x.first;
       maxCount = x.second;
     }
  }
  return resultString;
}


// more optimised 

#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    unordered_map<string, int> scores;
    string currentBestTeam = "";
    int maxScore = 0;

    for (int i = 0; i < competitions.size(); i++) {
        string winner = results[i] == 1 ? competitions[i][0] : competitions[i][1];
        scores[winner] += 3;  // Increment the winning team's score by 3

        if (scores[winner] > maxScore) {
            maxScore = scores[winner];
            currentBestTeam = winner;
        }
    }

    return currentBestTeam;
}