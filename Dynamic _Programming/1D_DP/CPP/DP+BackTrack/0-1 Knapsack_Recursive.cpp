#include <iostream>
using namespace std;

// backtracking No dp

int w[1000];	// wight of iteam
int items_size;
int c[1000];	// cost of iteam
int bag = 0;	// bag to store
int W;	// max we can store in bag
int visited[1000];
int maxCost = -1e9;
int currCost = 0;

int max(int x, int y)
{
  return (x > y) ? x : y;
}

int solve()
{
  if (bag == W)
  {
    maxCost = max(currCost, bag);
    return 1;
  }

  if (bag > W) return 0;

  for (int i = 1; i <= items_size; i++)
  {
    if (visited[i] == 0)
    {
      visited[i] = 1;
      bag += w[i];
      currCost += c[i];
      solve();
      currCost -= c[i];
      bag -= w[i];
      visited[i] = 0;
    }
  }

  return 1;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cin >> items_size;
    for (int i = 1; i <= items_size; i++)
    {
      cin >> w[i];
      visited[i] = 0;
    }

    for (int i = 1; i <= items_size; i++)
    {
      cin >> c[i];
    }

    bag = 0;
    cin >> W;
    maxCost = -1e9;
    solve();
    cout << "Case#" << i << ": " << maxCost << "\n";
  }
}

/*
1
3
10 20 30
60 100 120
50

*/

/*
 vector<int> w = {10, 20, 30};

 vector<int> c = {60, 100, 120};

*/