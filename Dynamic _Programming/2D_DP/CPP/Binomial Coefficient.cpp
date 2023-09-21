#include <iostream>
using namespace std;

/*
Binomial Coefficient
The binomial Coefficent are the most important class of counting numbers where 
(n k) counts the numbers of ways to choose K things out of n Possibility
basically kitne bar you can choose k things n possiblity se.

(n k) = n!/(n-k)!.k!
above equation cause bhasad 

this question can be solved using pascal traingle
1
11
121
1331

(3,2) = 3  there are 3 ways we can choose 2 things with 2 possibilty (12 23 13)
*/

int binomial_Coefficient(int N, int K)
{
  int **pascalTringle = new int *[N + 1];
  for (int i = 0; i < N + 1; i++) pascalTringle[i] = new int[N + 1];

 	// setting boudary

  for (int i = 0; i <= N; i++) pascalTringle[i][0] = 1;

  for (int i = 0; i <= N; i++) pascalTringle[i][i] = 1;

 	// (n,k) = (n-1,k-1) + (n-1,k) 
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j < i; j++)
    {
      pascalTringle[i][j] = pascalTringle[i - 1][j - 1] + pascalTringle[i - 1][j];
    }
  }

  return pascalTringle[N][K];

}

int main()
{
  int n = 10;
  int r = 5;
  cout << binomial_Coefficient(n, r) << "\n";
}