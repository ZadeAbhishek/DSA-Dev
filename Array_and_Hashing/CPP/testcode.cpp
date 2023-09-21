#include<bits/stdc++.h>
using namespace std;

int main (){
    char s = '3';
    cout<<(int)s - 48;
}

// ideas is to use for loop in which we compare each element with other element 
// index_i represents outer loop and index_j presents inner loop 

// outer loop
 for(auto outer = 0 ; outer < size(list) ; outer++)
 {
    // inner loop
    for(auto inner = 0; inner < size(list) ; inner++)
    {
           //compare each elements here
           // so if index's is not same and arr[inner] and arr[outer] are equal that means they are repeating 
           if(list[outer] = list[inner] || inner != outer) return false;
    }
 }
 // else everything is okay return
 return true;