/*
You are given N unique numbers a1<a2<a3<...an. Find out the count of all possible binary search 
trees that can be constructed using these numbers. For example with 3 elements 1,2,3, there are 
5 possible BST and for 1,2,3,4 there are 14 BST.


intution
i think this can be solved using catalans number equaltion
gfg : https://www.geeksforgeeks.org/program-nth-catalan-number/

now given there will be unique number so no matter what this question no about given but the 
size/quantity of number. put in this way lets say
we have 2 array as i/p

1 ==> 23 45 67 89
2 ==> 1  2  3  4

if we cal calute both have anw same i.e 14

so we can this using catalan number

*/

#include<iostream>
using namespace std;

unsigned long getCombination(unsigned int n){
     
     if(n <=1) return 1;

     unsigned long int ans = 0;

     for(int i = 1 ; i <= n ; i++){
        ans += getCombination(i-1) * getCombination(n-i);
     }

     return ans;
}


int main(){
    int totalTest;
    cin>>totalTest;
    while(totalTest--){
        int elements;
        cin>>elements;
        int *arr = new int[elements];
        for(int i = 0 ; i < elements ; i++){
            cin>>arr[i];
        }
        cout<<endl;
        cout<<getCombination(elements)<<endl;
    }
}

/*
testcase
2
4
1 2 3 4
4
23 45 67 89

*/