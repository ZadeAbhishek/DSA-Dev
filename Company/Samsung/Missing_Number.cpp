/*
gfg https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

You are given an unsorted array with both positive and negative elements. You have to find the smallest positive number missing from the array in O(n) time using constant extra space.

**Input:** First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

**Output:** Single line output, print the smallest positive number missing.

**Constraints:**

1<=T<=100 and 1<=N<=100

**Example:**
```
Input:
3
5
1 2 3 4 5
5
0 -10 1 3 -20
10
5 7 6 -10 2 3 -9 -1 8 9

3
0 1 2
Output:
6
2
1


1
5
1 0 3 3 2



1
5
1 1 0 -1 -2
8
2 3 -7 6 8 1 -10 15

output
1
4
```
*/

// assuming no librabry can be used
#include<iostream>
using namespace std;


int getMissing(int *arr, int n){
    
    // check for one if one is not present then return 1
    // since 1 is the smallest number
    bool oneFlag = true;
    for(int i = 0 ; i < n ; i++){
          if(arr[i] == 1) oneFlag = false;
    }
    if(oneFlag) return 1;

    // since one is present
    // we will hangle negative number and out off range number
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < 0 || arr[i] > n) arr[i] = 1;
    }

    // adding array with max lenght
    for(int i = 0 ; i < n ; i++){
        arr[(arr[i]-1) % n] +=n; 
    }

    // get missing element
    for(int i = 0 ; i < n ;i++){
        if(arr[i] <= n) return i + 1;
    }

    return n+1;
}


/// leetcode

    int firstMissingPositive(int *nums, int n) {
         // check for one if one is not present then return 1
    // since 1 is the smallest number
    for(int i = 0 ; i < n ; i++){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
            swap(nums[i], nums[nums[i]-1]);
        }
    }

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i + 1) return i + 1;
        }
    return n + 1;
}

int main(){
    int tc;
    cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }
        //cout<<"Case#"<<i<<" "<<getMissing(arr,n)<<endl;
        cout<<firstMissingPositive(arr,n)<<"\n";
    }
    return 0;
}