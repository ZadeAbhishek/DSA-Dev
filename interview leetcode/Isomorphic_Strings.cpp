#include<bits/stdc++.h>
using namespace std;

 bool isIsomorphicc(string s, string t) {
        
        if(size(s) != size(t)) return false;
        
        // idea is to use hashmap here for key value pair
       vector<char> s_vec(200,0);
       vector<char> t_vec(200,0);

       for(auto i = 0 ; i < size(s); i++) s_vec[(int)s[i]]++;
       for(auto i = 0 ; i < size(t); i++) t_vec[(int)t[i]]++;

       int s_count = 0;
       int t_count = 0;
       for(auto i = 0 ; i < 200 ; i++)
       {
        if(s_vec[i] >= 1) s_count++;
        if(t_vec[i] >= 1) t_count++;
       }

       if(s_count == t_count) return true;
       else return false; 
        
 }  


  bool isIsomorphic(string s, string t) {
        
        if(size(s) != size(t)) return false;
        
      vector<char> s_vec(200,0);
      vector<char> t_vec(200,0);

       for(auto i = 0 ; i < size(s) ; i++)
       {
          if(s_vec[(int)s[i]] == 0 && t_vec[(int)t[i]] == 0)
          {
            s_vec[(int)s[i]] = (int)t[i];
            t_vec[(int)t[i]] = (int)s[i];
          }

          if(s_vec[(int)s[i]] != (int)t[i] || t_vec[(int)t[i]] != (int)s[i]) return false;


         // s_vec[(int)s[i]] == (int)t[i]
       }

       return true;
        
 }  

int main (){

    string s = "ababa";

    string t = "acace";

    cout<<isIsomorphic(s,t);
  
}