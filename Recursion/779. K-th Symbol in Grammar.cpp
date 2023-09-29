#include<iostream>
#include<vector>

// Brute force TLE n = 30 k = 434991989
int solveTabMethod(int n, int k){
    std::vector<std::vector<int>> tab(n,std::vector<int>());
    tab[0].push_back(0);
    for(auto i = 1; i < n; i++){
        for(auto j = 0; j < tab[i-1].size(); j++){
            if(tab[i-1][j] == 0){
                tab[i].push_back(0);
                tab[i].push_back(1);
            }
            if(tab[i-1][j] == 1){
                tab[i].push_back(1);
                tab[i].push_back(0);
            }
        }
    }
    return tab[n-1][k-1];

}

// recursive
 class Solution {
  public: int kthGrammar(int n, int k) {
    // represents height of tree
    // min Height will always be 1
    if (n == 1) return 0; // becase root will start at one
    //oservation if prev is 0 then right is always one and left is always 0
    // if prev is 1 left is 0 right is 1
    // check if curr is left of right
    if (k % 2 == 0) return (kthGrammar(n - 1, k / 2)) == 0 ? 1 : 0;
    else return (kthGrammar(n - 1, (k + 1) / 2)) == 0 ? 0 : 1; //make it even and send
  }
};


int main(){
    int n = 2;
    int k = 2;
    std::cout<<solveTabMethod(n,k)<<"\n";
}