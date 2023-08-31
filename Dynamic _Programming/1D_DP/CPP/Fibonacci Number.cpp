#include <iostream>
#include <string.h>
using namespace std;

int a[10000];

// this is recursive version of this with memory 
// TC O(n);
// SC O(n) + aulillary stack for recussion  
int fib(int n)
{
  if (n == 0 || n == 1) return n;

  if (a[n] != -1) return a[n];

  return a[n] = fib(n - 1) + fib(n - 2);
}

// this optimised than recursive with memory 
// TC O(n)
// SC O(n) here we are not using auxillary stack space
int fib_linear(int n)
{
  // edge case
  if(n == 0 || n == 1) return n;

  int table[n + 1];
  for (int i = 0; i < n + 1; i++) table[i] = -1;
  table[0] = 0;
  table[1] = 1;
  for (int i = 2; i <= n; i++) table[i] = table[i - 1] + table[i - 2];
  return table[n];
}

// more optimised than previous
// TC : O(n)
// SC : O(1)
int fib_Linear_Optimised(int n)
{
  // edge case
  if(n == 0 || n == 1) return n;
  
  int curr = 0;
  int prev = 0;
  int Twoprev = 1;
  for (int i = 2; i <= n; i++)
  {
    curr = prev + Twoprev;
    prev = Twoprev;
    Twoprev = curr;
  }

  return curr;
}


int fib_Linear_Optimised_print(int n)
{
  // edge case
  if(n == 0 || n == 1) return n;
  
  int curr = 0;
  int prev = 0;
  int Twoprev = 1;
  cout<<0<<" "<<1<<" ";
  for (int i = 2; i <= n; i++)
  {
    curr = prev + Twoprev;
    cout<<curr<<" ";
    prev = Twoprev;
    Twoprev = curr;
  }
  cout<<"\n";
  return curr;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) a[i] = -1;
  a[0] = 0;
  a[1] = 1;
  cout << fib_Linear_Optimised_print(n) << "\n";
}