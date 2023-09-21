/*

Problem https://www.hackerearth.com/problem/algorithm/question-7-4/

testcase 
2    
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1

explainatio of test case
2             	// no of test case
5 6 2 1 3     	// height width startX startY lenghtofEndoscope
0 0 5 3 6 0   	// matrix or board
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
*/

// This problem can be solved using BFS

/*
Accroding to question we can see
pipes in which respective side occurs

left = 1 3 6 7
right = 1 3 4 5
top = 1 2 4 7
bottom = 1 2 5 6

*/
#include <iostream>
using namespace std;

int height, width, startX, startY, lenght;
int area[1000][1000];
int visitedArea[1000][1000];

//queue make is zero init function
int front;
int back;

// function tp check the validity of coordinates
bool isValid(int x, int y)
{
	if (x >= 0 && y >= 0 && x <= height - 1 && y <= width - 1) return true;
	return false;
}

// check side is available for this coordinates
int left(int x, int y)
{
	if (area[x][y] == 1 || area[x][y] == 3 || area[x][y] == 6 || area[x][y] == 7) return true;
	return false;
}

int right(int x, int y)
{
	if (area[x][y] == 1 || area[x][y] == 3 || area[x][y] == 4 || area[x][y] == 5) return true;
	return false;
}
int top(int x, int y)
{
	if (area[x][y] == 1 || area[x][y] == 2 || area[x][y] == 4 || area[x][y] == 7) return true;
	return false;
}

int bottom(int x, int y)
{
	if (area[x][y] == 1 || area[x][y] == 2 || area[x][y] == 6 || area[x][y] == 5) return true;
	return false;
}

struct pipe
{
	int x, y;	// corrdinate
	int l;	// lenght
};

pipe queue[1000000];	// set to max size

void push_to_queue(pipe temp)
{
	queue[back++] = temp;
	return;
}

pipe pop_from_queue()
{
	return queue[front++];	// instead of delete just return the front part and move front
}

bool empty()
{
	return front == back;
}

// function to traverse in forn of bfs
int start_Bfs(int x, int y, int l)
{
	// x and y are inital point were pipe is present;
	int ans = 0;	// check track of no of pipes to traverse
	visitedArea[x][y] = 1;
	pipe temp = { x, y, l
	};

	push_to_queue(temp);	// push iniital in queue;

	while (!empty())
	{
		pipe curr = pop_from_queue();
		int currx = curr.x;
		int curry = curr.y;
		int currLenght = curr.l;
		if (currLenght == 0) continue;	// we cannot travse futher more

		ans++;

		// check for all sides
		int direction[][2] = {{ 0, -1 },{ 0, 1 },{ 1, 0 },{-1, 0}};

		for (int i = 0; i < 4; i++)
		{
			// check if curr pipe has opening of that side and also check for its correspoding side
			// for example check if curr side has left side and its repect side has left side open if yes push that coordinate to queueu;

			// repeative can optimise this
			if (i == 0 && isValid(currx + direction[i][0], curry + direction[i][1]) && left(currx, curry) && left(currx + direction[i][0], curry + direction[i][1]) && visitedArea[currx + direction[i][0]][curry + direction[i][1]] == 0)
			{
				push_to_queue({ currx + direction[i][0], curry + direction[i][1], currLenght - 1 });
				visitedArea[currx + direction[i][0]][curry + direction[i][1]] = 1;
			}

			if (i == 1 && isValid(currx + direction[i][0], curry + direction[i][1]) && right(currx, curry) && right(currx + direction[i][0], curry + direction[i][1]) && visitedArea[currx + direction[i][0]][curry + direction[i][1]] == 0)
			{
				push_to_queue({ currx + direction[i][0], curry + direction[i][1], currLenght - 1 });
				visitedArea[currx + direction[i][0]][curry + direction[i][1]] = 1;
			}

			if (i == 2 && isValid(currx + direction[i][0], curry + direction[i][1]) && top(currx, curry) && top(currx + direction[i][0], curry + direction[i][1]) && visitedArea[currx + direction[i][0]][curry + direction[i][1]] == 0)
			{
				push_to_queue({ currx + direction[i][0], curry + direction[i][1], currLenght - 1 });
				visitedArea[currx + direction[i][0]][curry + direction[i][1]] = 1;
			}

			if (i == 3 && isValid(currx + direction[i][0], curry + direction[i][1]) && bottom(currx, curry) && bottom(currx + direction[i][0], curry + direction[i][1]) && visitedArea[currx + direction[i][0]][curry + direction[i][1]] == 0)
			{
				push_to_queue({ currx + direction[i][0], curry + direction[i][1], currLenght - 1 });
				visitedArea[currx + direction[i][0]][curry + direction[i][1]] = 1;
			}
		}
	}

	return ans;
}

int main()
{
	int totalTestCase;
	cin >> totalTestCase;
	while (totalTestCase--)
	{
		cin >> height >> width >> startX >> startY >> lenght;
		front = 0;
		back = 0;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				visitedArea[i][j] = 0;
				cin >> area[i][j];
			}
		}

		cout << start_Bfs(startX, startY, lenght) << endl;
	}
}

/*
explainatio of test case
2             	// no of test case
5 6 2 1 3     	// height width startX startY lenghtofEndoscope
0 0 5 3 6 0   	// matrix or board
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

*/