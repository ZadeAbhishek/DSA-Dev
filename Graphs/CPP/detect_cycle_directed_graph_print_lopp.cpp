// detect_cycle_directed_graph_print_loop

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// task is to detect cycle in directed Graph
// so parent wont word here instead we can use dfsVisited flag for each node

// global varaiable
int graph[100][100];
int dfsVisited[100];	// this is to track if the current node is visited in current call or not
int visited[100];
int nodes;
int edges;
int cycleStart = -1;
int canPush = 0;

// path trassor
vector<int> path;

bool detectCycle(int curr)
{
	visited[curr] = 1;	// mark visited (this will be permanant vivisted)
	dfsVisited[curr] = 1;	// msk visited(this will temporary till this call and recurrsinve next to this calls)
	for (int i = 0; i < nodes; i++)
	{
		// if eges is present
		if (graph[curr][i] == 1)
		{
			// check if visited or not
			if (visited[i] == 0)
			{
			 	// not visited then visit 
				if(detectCycle(i)){
                    if(canPush) path.push_back(i);
                    if(cycleStart == i) canPush = 0;
                    return true;
                }
                else return false;
			}
			else if (visited[i] == 1 && dfsVisited[i] == 0)
			{
				//check if visisted and before this call also it is visited or not

				return false;
			}
			else if (visited[i] == 1 && dfsVisited[i] == 1)
			{
				//check if the visited and also visited in same call this means cycle return true
				// cycle return true
                cycleStart = i;
                canPush = 1;
				return true;
			}
		}
	}

	// if not cycle unvisited this
	dfsVisited[curr] = 0;
	return false;
}

bool dfs()
{
	// we are going to call for each nodes there and check if the there is cycle

	for (int curr = 0; curr < nodes; curr++)
	{
		if (!visited[curr] && detectCycle(curr))
		{
			return true;
		}
		else false;
	}

	return false;
}

int main()
{
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		cin >> nodes;
		int n = nodes;

		// initialise
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				graph[i][j] = 0;
				visited[i] = 0;
				dfsVisited[i] = 0;
			}
		}

		cin >> edges;
		int temp = edges;
		while (temp--)
		{
			int x;
			int y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
        
		cout << dfs() << "\n";

        for(auto x : path) cout<<x<<" ";
        cout<<"\n";
        cout<<cycleStart<<"\n";
	}
}

/*

total Test case  => 1
totals Node(n+1) => 4
total edges      => 3
0 1
1 2
2 3
3 0
op 1

1
5
6
0 1
1 2
2 3
1 3
3 4
4 2

op 1

1
5
6
0 1
1 2
2 3
1 3
3 4
2 4

op 0

1
8
9
0 1
1 2
2 5
2 3
3 4
5 6
6 1
6 7
7 5

op 1

*/