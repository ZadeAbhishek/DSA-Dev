// question https://practice.geeksforgeeks.org/problems/find-last-digit-of-ab-for-large-numbers1936/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// explanation https://practice.geeksforgeeks.org/problems/find-last-digit-of-ab-for-large-numbers1936/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
    
    int Modulo(int a, string b){
        int mod = 0;
        
        // calculating mod of b with a to make
        // b like 0 <= b < a

        for(int i = 0; i < b.size() ; i++){
             mod = (mod * 10 + (b[i] - '0')) % a;
        }
        // ex 1234
        // mod = (0 * 10 + 1) % 4  ==> mod = 1 % 4  ==>  1;
        // mod = (1 * 10 + 2) % 4  ==> mod = 12 % 4 ==> 0;
        // mod = (0 * 10 + 3) % 4  ==> mod = 3 % 4  ==>  3;
        // mod = (3 * 10 + 4) % 4  ==> mod = 34 % 4  ==>  2;
        // mod = 2;

        return mod;
    }



    int getLastDigit(string a, string b) {
        // base case
        
        // if a = 0 && b = 0
        if(a.size() == 1 && b.size() == 1 && a[0] == '0' && b[0] == '0') return 1;
        // if a = 0
        if(a.size() == 1 && a[0] == '0') return 0;
        // if b = 0
        if(b.size() == 1 && b[0] == '0') return 1;

        int power = Modulo(4,b); // power = 2 

        power = power == 0?4:power; 

        int result = pow(a[a.size()-1]-'0',power); // 3 ^ 2

        return result%10; // give lasr digit

    }
//{ Driver Code Starts.
int main() {
    string a = "3";
    string b = "1234";
    cout<<getLastDigit(a,b)<<"\n";
    return 0;
}