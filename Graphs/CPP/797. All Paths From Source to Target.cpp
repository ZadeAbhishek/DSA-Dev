class Solution {
  public:

    void allPathsSourceTarget(vector < vector < int >> & graph, vector < int > & temp, vector < vector < int >> & result, int curr, vector < int > & vis) {

      
      // if curr node is last push path and return
      if (curr == size(graph) - 1) { 
        result.push_back(temp);
      }
      // else iterater the curr node adjecent and return 
      else {
        for (auto iterator: graph[curr]) {
          if (!vis[iterator]) { // check for visibility
            vis[iterator] = 1;
            temp.push_back(iterator);
            allPathsSourceTarget(graph, temp, result, iterator, vis);
            temp.pop_back(); 
            vis[iterator] = 0;
          }
        }
      }

      return;

    }

  vector < vector < int >> allPathsSourceTarget(vector < vector < int >> & graph) {

    vector < int > vis(size(graph), 0); // to check for visited graphs so not to visit again
    vector < int > temp; // to push path
    vector < vector < int >> result; // to push all path
    temp.push_back(0); // we start with 0 (this is part is clear from question)
    allPathsSourceTarget(graph, temp, result, 0, vis); // call (here we are using pass by reference to save memory)
    return result; // return 
  }
};