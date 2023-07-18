/*

source:: https://github.com/s-kachroo/SamsungPractice/blob/master/omnious%20number.cpp#L1-L23

Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.

Example-

Range: 24 to 12943

Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more

In above case all two digit numbers are valid.

In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.

In four digit: All the numbers containing above 3 digit numbers are not valid.

Eg: 11223 is not valid, 11222 is valid.

input

1
24 12943 
3
1 3 5
3

op 10997

*/



#include<iostream>
using namespace std;


int getValidNumbers(int rangeStart, int rangeEnd, int *inValidNumbers,int inValidCount, int size){
    
    int validNumber = 0;
    
    for(int i = rangeStart ; i <= rangeEnd ; i++){
        // num is current number
         int num = i;
         
         int digits[10] = {0}; // 0 -- 9
 
         while(num){
            digits[num%10]++;
            num /= 10;
         }

         // count valid number
          
         int count = 0;

         for(int k = 0 ; k < size ; k++){
             count += digits[inValidNumbers[k]];
         }

         // check count is less than invalidcount
         if(count < inValidCount) validNumber++;
    }
    return validNumber;
}

int main(){
    int totalTest;
    cin>>totalTest;
    while(totalTest--){
        int rangeStart, rangeEnd;
        cin>>rangeStart>>rangeEnd;
        int size;
        cin>>size;
        int *inValidNumbers = new int[size]; // pointer to aaray
        for(int i = 0 ; i < size ; i++){
            cin>>inValidNumbers[i];
        }
        int inValidCount;
        cin>>inValidCount;

        cout<<getValidNumbers(rangeStart,rangeEnd,inValidNumbers,inValidCount,size)<<endl;
    }
}
