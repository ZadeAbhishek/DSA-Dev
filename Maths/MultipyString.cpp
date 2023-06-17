#include<bits/stdc++.h>
using namespace std;

void operator<< (ostream& Cout , vector<int> arr){
   for(auto x : arr){
    Cout<<x<<" ";
   }
   Cout<<endl;
}


class Solution {
public:
    string multiply(string num1, string num2) {
        // check if any string is equal to '0' if yes return
        // since x * 0 = 0
        if(num1 == "0" || num2 == "0") return "0";
        // num1.reserve();
        // num2.reserve();
        vector<int> temp(num1.size()+num2.size());
        for(signed int i = num1.size()-1 ; i >= 0 ; i --){
            for(signed int j = num2.size()-1 ; j >= 0 ; j--){
                temp[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                temp[i+j] += temp[i+j+1]/10;
                temp[i+j+1] = temp[i+j+1]%10; 
            }
        }
    int i = 0;
    while(temp[i] == 0) i++;
    string r = "";
    while(i < temp.size()) r += to_string(temp[i++]); 
    return r;
    }

};

int main(){
    Solution *s;
    cout<<s->multiply("123","456");
}