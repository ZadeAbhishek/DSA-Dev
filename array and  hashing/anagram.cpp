#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    unordered_map<char,int> s1;
    unordered_map<char,int> s2;
public:
   bool isAnagram(string s, string t) {
       for(auto  i = 0; i < s.size(); i++){
           if(!s1.count(s[i])){
             s1.insert({s[i],1});
           }
           else{
           s1[s[i]]++;
           }
           }
      for(auto  i = 0; i < t.size(); i++){
           if(!s2.count(t[i])){
             s2.insert({t[i],1});
           }
           else
           {
           s2[t[i]]++;
           }
        }
        int count1 = 0;
        int count2 = 0;
         for(auto  i = 97; i <= 122; i++){
            char c = i;
             if(s1[i] != s2[i]){
                return false;
             }
            //  cout<<c<<endl;
            //  cout<<"C1"<<count1<<endl;
            //  cout<<"C2"<<count2<<endl;
        }
        //if(count1 == count2){ return true;}
        return true;
   }
};




// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int string_s_len = s.size();
//         int string_t_len = t.size();
//         int count = 0;
//         s = sortString(s);
//         t = sortString(t);
//         while(string_s_len == string_t_len){
            
//             if(int(s[count])!=int(t[count])){
//                 return false;
//             }
//             if(count == string_s_len ){
//               return true;
//             }
//            count++;
//         }
//         return false;
//     }
// string sortString(string &str)
// {
//    sort(str.begin(), str.end());
//    return str;
// }
    
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
//};
int main (){
     string  s = "ccca";
     string  t = "caaa"; 
    Solution* solve = new Solution();    
    bool result = solve->isAnagram(s,t);
    cout<<result<<" "<<endl;

}