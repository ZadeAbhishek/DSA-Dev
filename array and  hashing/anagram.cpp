#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int string_s_len = s.size();
        int string_t_len = t.size();
        int count = 0;
        s = sortString(s);
        t = sortString(t);
        while(string_s_len == string_t_len){
            
            if(int(s[count])!=int(t[count])){
                return false;
            }
            if(count == string_s_len ){
              return true;
            }
           count++;
        }
        return false;
    }
string sortString(string &str)
{
   sort(str.begin(), str.end());
   return str;
}
    
//    string sort(string s){
//      int len = s.size();
//      int high = len;
//      int low = 0;
//      string l = sort(s,low,high);
//      return l;
//    } 
//    string sort(string s,int l, int h){
//     int m = (h+l)/2;
//     if(h == l){
//         return s;
//     }
//     string t = "";
//     sort(s,l,m);
//     sort(s,m,h);
//     return t;
// } 
};
int main (){
     string  s = "a";
     string  t = "ab"; 
    Solution* solve = new Solution();    
    bool result = solve->isAnagram(s,t);
    cout<<result<<" "<<endl;

}