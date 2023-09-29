// this is DP problem Solve when stduing Dp 

#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include <queue>
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        char prev = '`';
        int count = 0;
        string temp;
        int alpha[122];
         for(int i=0;i<122;i++){
            alpha[i]= 0;
         }
         for(int j=s.size()-1; j>=0 ; j--){
            int index = int(s[j]);
            if(int(prev) == index){
                  alpha[index]++;
            }
            int q = int(s[j]-k);
            int r = int(s[j]+k);
            //cout<<index<<endl;
            if(q<97){ 
                q = 97;}
            if(r>122){r = 122;}
          // cout<<"Char:"<<char(index)<<endl;
           //cout<<"Range:("<<char(q)<<","<<char(r)<<")"<<endl;
             
            for (int i = q; i<=r;i++){
               
                if(alpha[index]==0){
                    alpha[index]++;
                }
                if(alpha[i]>=alpha[index] && i!=index){
                    alpha[index] = max(alpha[i],alpha[index])+1; 
                }
                
            }
             char temp = index;  
              prev = temp;
         }
          for(int i=97;i<=122;i++){
             if(alpha[i]>count){
                count = max(alpha[i],count);
             }
        //cout<<count<<endl;
              
          }
         
          
         return count;
    }
};
int main (){
    string  s = "abcd";
    Solution* solve = new Solution();    
    int result = 0; 
    result = solve->longestIdealString(s,16);
    cout<<result;
    cout<<endl;
    return 0;
}
