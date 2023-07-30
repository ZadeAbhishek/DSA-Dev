//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// O(N^2);
   int pallindrome(string &s,int start , int end){
    while(start < end){
        if(s[start] != s[end]) return false;
        start++,end--;
    }
    return true;
}

int minChar(string str){
    int lenght = str.size();
    int count = 0;

    while (lenght > 0)
    {
        if(pallindrome(str,0,lenght-count)){ break;}
        else count++;
    }
    return count;
    
}


int minChar2(string str){
    int lenght = str.size();
    int end = lenght-1;
    int count = 0;
    int start = 0;
    while(start < end){
        cout<<str[start]<<" "<<str[end]<<"\n";
        if(str[start] == str[end] && pallindrome(str,start,end)) break;
        else{
            count++;
            end--;
        }
    }
    return count;
    
}


int minChar3(string str){
    int lenght = str.size();
    int end = lenght-1;
    int count = 0;
    int start = 0;
    while(start <= end){
        cout<<str[start]<<" "<<str[end]<<"\n";
        if(str[start] == str[end]) start++,end--;
        else{
            count++;
            end--;
        }
    }
    return count;
    
}

// KMP solution 
vector<int> computeLPSArray(string s)
{
    int n = s.length();
    vector<int> LPS(n);
 
    int len = 0;
    LPS[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = LPS[len-1];
            }
            else 
            {
                LPS[i] = 0;
                i++;
            }
        }
        cout<<LPS[i]<<" ";
    }
    cout<<"\n";
    return LPS;
}
int solve(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    string c = s + "$" + rs;
    vector<int> LPS = computeLPSArray(c);
    return (s.length() - LPS.back());
}

int minChar4(string str){
   return solve(str);
    
}


//{ Driver Code Starts.
int main()
{
	string s = "bb";
    cout<<minChar4(s)<<"\n";

}

// } Driver Code Ends