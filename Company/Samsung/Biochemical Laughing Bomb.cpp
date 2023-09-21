/*
You are busy to promote a newly released film in a movie theater. The title is ‘Biochemical Laughing Bomb’ which is about terror.
Guerrillas drop a biochemical laughing bomb in the middle of a city. Once exposed, you have to laugh all your life. The bomb will contaminate four people around it during 1 second, and another four around each of them during another one second. However, you won’t be contaminated if you are not in the adjacent four directions. as the below shows the location of the bomb and affected people, and shows contamination process in seconds and you can figure out that the whole city is contaminated in 8 seconds.
In order to protect the city from the epidemic, create a program that figures out when the city will be contaminated by the bomb for the last.

Time limit: 1 second (java: 2 seconds)
[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row.
The row and column of the city, N and M are given by being separated with a blank on the first row of each test case. (1 ≤ N, M ≤ 100)
The status within city is given by being separated with a blank from the second row to N number rows. 1 means people exist and 0 means people do not exist.
The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.
[Output]
For each test case, you should print "Case #T" in the first line where T means the case number. For each test case, you should output how long does it take to contaminate al people on the first row of each test case.
[I/O Example]

Input
2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
2 5
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

1
3 3
1 1 1
1 1 1
1 1 0
0 0

Output
Case #1

8

Case #2
21

*/
#include <iostream>
#include <queue>
using namespace std;

int area[105][105];
int N, M;
int X, Y;
int level = -1;
int visited[105][105];

int dir[4][2] = {
		{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{-1, 0
	}
};

struct person
{
	int x;
	int y;
	int level;
};

bool valid(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return false;
	return true;
}

// basic bfs should work here
void bfs()
{
	person d;
	d.x = X;
	d.y = Y;
	d.level = 1;	// we have to check this
	queue<person> q;
	q.push(d);
	while (!q.empty())
	{
		person dx = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int currX = dx.x + (dir[i][0]);
			int currY = dx.y + (dir[i][1]);
			int currL = dx.level + 1;

			if (valid(currX, currY) && visited[currX][currY] == 0)
			{
				visited[currX][currY] = 1;
				level = max(currL, level);

				if (area[currX][currY] == 1)
				{
					person pd;
					pd.x = currX;
					pd.y = currY;
					pd.level = currL;
					q.push(pd);
				}
			}
		}
	}
}

int main()
{
	int Tcase;
	cin >> Tcase;
	int t = 1;
	while (t <= Tcase)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> area[i][j];
				visited[i][j] = 0;
			}
		}

		cin >> X >> Y;
		visited[X][Y] = 1;
		bfs();
		cout << "#" << t << " " << level - 1 << "\n";
		t++;
	}
}