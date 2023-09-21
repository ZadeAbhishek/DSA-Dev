// here Negative numbers can also came so that time use hashmap

#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[1000000] = { 0 };
  long long x;
  int size;
  cout<<"Enter size of i/p array ";
  cin>>size;
  for(auto i = 0 ; i < size ; i++) {
      cin>>x;
      arr[x]++;
}
  
  for(auto i = 0 ; i < 1000000 ; i++){
      if(arr[i] != 0) cout<<i<<" "<<arr[i]<<"\n";
 }
}