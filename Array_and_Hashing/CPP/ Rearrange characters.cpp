/* purpose is to determine whether it's possible to rearrange the characters in the input 
   string str in such a way that no two adjacent characters are the same. */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        vector<int> count(256,0);
        
        for(auto &x : str) count[(int)x]++;
        
        // we need to count even and odd
        int even = 0; // get distct even pair 
        int odd = 0;
        for(auto &x : count){
            if(x == 0) continue;
            if(x % 2 == 0){

                // check for even we need to balancve even 
                if(even - x/2 >= 0) even -= x/2;
                else even += x/2;
            }
            else{
                odd += x;
            }
        }
        
        
        if(even == 0) return "1";
        
        else if(even > odd && (even - odd == 1)) return "1";
        
        else if(odd > even) return "1";
        
        else return "0";
        
        
    }
    
};

int main() {
    Solution solution;

    // Example input: a string to be rearranged
    string inputString = "aabbcc";

    string rearrangedString = solution.rearrangeString(inputString);

    cout << "Rearranged string: " << rearrangedString << endl;

    return 0;
}
