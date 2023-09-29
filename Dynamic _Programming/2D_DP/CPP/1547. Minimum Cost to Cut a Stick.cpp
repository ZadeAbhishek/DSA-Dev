/*
https://www.youtube.com/watch?v=xwomavsC86c&ab_channel=takeUforward
*/
// partion dp example
class Solution {
public:
    
    int cutStick(vector<int>& cuts,int i, int j,vector<vector<int>> &memo){
        // base case 
        if(i>j) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        // main case
        int minCost = INT_MAX;
        for(int k = i ; k <= j ; k++){ // k represents cuts
            int cost = cuts[j+1] - cuts[i-1]  + cutStick(cuts,i,k-1,memo) + cutStick(cuts,k+1,j,memo);
            minCost = min(cost,minCost);
        }
        return memo[i][j] = minCost;
    }


    int minCost(int n, vector<int>& cuts) {
        // inital cost would be n
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> memo(size+1,vector<int>(size+1,-1));
        return cutStick(cuts,1,size,memo);

    }
};

// tc O(n^2 * n) = O(n^3) n^2 because we are using i and j n for for loop of k
// sc O(n^2) + auxilary stack
// partion dp
class Solution {
   public:

      // tabulation method
      int minCost(int n, vector < int > & cuts) {
         // inital cost would be n
         int size = cuts.size();
         cuts.push_back(n);
         cuts.insert(cuts.begin(), 0);
         sort(cuts.begin(), cuts.end());
         vector < vector < int >> memo(size + 2, vector < int > (size + 2, 0));
         for (int i = size; i >= 1; i--) {
            for (int j = 1; j <= size; j++) {
               if (i > j) continue;
               int minCost = INT_MAX;
               for (int k = i; k <= j; k++) {
                  int cost = cuts[j + 1] - cuts[i - 1] + memo[i][k - 1] + memo[k + 1][j];
                  minCost = min(cost, minCost);
               }
               memo[i][j] = minCost;
            }
         }
         return memo[1][size]; // i is going from size to 1 anf j is ging from 1 to size therefore last result will be stored in 1,size

      }
};

// tc O(n^2 * n) = O(n^3) n^2 because we are using i and j n for for loop of k
// sc O(n^2) 