#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>


int getDecimal(std::string &s){
    int ans = 0;
    std::reverse(s.begin(),s.end());
    for(int i = 0 ; i <= 32 ; i++){
         if(s[i]  == '1') ans += std::pow(2,i); 
    }
    std::cout<<ans<<"\n";
}

int main(){
    std::string s = "000000000000000000000000001100000";
    getDecimal(s); 
}