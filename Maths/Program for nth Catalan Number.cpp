/*
Catalan numbers are defined as a mathematical sequence that consists of positive integers, 
which can be used to find the number of possibilities of various combinations. 

The nth term in the sequence denoted Cn, is found in the following formula: 

use case 

* Count the number of expressions containing n pairs of parentheses that are correctly matched. 
  For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

* Count the number of possible Binary Search Trees with n keys (See this)

* Count the number of full binary trees (A rooted binary tree is full if every vertex has either 
  two children or no children) with n+1 leaves.

* Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points 
  such that no 2 chords intersect.

*/


#include <iostream>
using namespace std;
 
// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
 
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 1; i <= n; i++)
        res += catalan(i-1) * catalan(n - i);
 
    return res;
}
 
// Driver code
int main()
{
    // for (int i = 0; i < 10; i++)
    //     cout << catalan(i) << " ";
    // return 0;

     cout<<catalan(4)<<"\n";
}

// op 1 1 2 5 14 42 132 429 1430 4862 

/*

formula 
n = 1 
n+1 = n * (4(n+1)+2)/((n+1)+2); 

optimised opproch 
class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for(int i = 0; i < n; i++) 
            ans *= (4*i+2) / (i+2);
        return ans;
    }
};


*/