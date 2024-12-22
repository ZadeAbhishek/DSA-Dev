/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string text;
    cin>>text;
    int maxSize = 0;
    int counter = 0;
    for(auto i = 1 ; i < text.size(); i++){
       if(text[i] == text[i-1]) counter++;
       else {
        maxSize = max(counter+1,maxSize);
        counter = 0;
       }
    }
    maxSize = max(maxSize, counter + 1);
    cout<<maxSize<<"\n";
    return 0;
}