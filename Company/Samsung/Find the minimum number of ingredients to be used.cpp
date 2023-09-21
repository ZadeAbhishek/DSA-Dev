/*

// Find the minimum number of ingredients to be used
//  https://discuss.codechef.com/t/find-the-minimum-number-of-ingredients-to-be-used/53551
// https://www.geeksforgeeks.org/samsung-software-competency-test-swc-for-working-professionals/

Question: 

Input: Given T test cases. 

For each test cases, k is given. k is the number of ingredients. 

Following k, there are k lines. Each line has 3 numbers. They represent protein, fat and carbohydrate content in the kth ingredient. 

Following these k lines, 3 lines are given. Each line has 3 numbers. They represent protein, fat and carbohydrate. For these 3 targets, we need to find out the ingredients to be added to exactly match the target. 

Output: for the 3 lines in each test case, print space separated numbers denoting the ingredients to be added to get the exact match. 
The ingredients must be printed in the sorted order. If there are many combinations, print the one which minimum number of ingredients. 

Sample input/output: 

1             	//testcases 
5            	// 5 ingredients 
1 2 3      	//1st ingredient 
4 5 6     	//2nd .. 
7 8 9 
9 18 12 
5 7 9      	//5th ingredient 
5 7 9      	//1st target 
11 13 15 	//2nd target 
52 14 3 	// 3rd target 

Expected output: 

5 
2 3 
-1 

Note: -1, when no combination(s) found 

*/
#include <iostream>
using namespace std;

// structure to store macros
struct macro
{
	int p;
	int c;
	int f;
};

// queue to curr macros index
// we can use any other data structure to store this
int *queue = new int[1000];
int front = 0;
int back = -1;

// pointers
macro * macroList;	// macro list input
macro * targets;	// targets to need to find
int Size;	// size of macrolist
int **result;	// min combination will be stored here
int minSize;	// curr min size of the combination
int *sizeMin;	// to track all size of array in result array

// function to get the all combination 
void getCombination(macro r, int target, int curr)
{
	// base case 
	if (curr > Size) return;

	if (r.c > targets[target].c && r.f > targets[target].f && r.p > targets[target].p)
	{
		return;
	}

	// match case 
	if (r.c == targets[target].c && r.f == targets[target].f && r.p == targets[target].p)
	{
		if (back - front + 1 < minSize)
		{
			minSize = (back - front) + 1;
			sizeMin[target] = minSize;
			result[target] = new int[back - front + 1];
			for (int i = front; i <= back; i++)
			{
				result[target][i] = queue[i] + 1;
			}
		}

		return;
	}

	// backtrack
	// add curr 
	r.c += macroList[curr].c;
	r.f += macroList[curr].f;
	r.p += macroList[curr].p;
	back++;
	queue[back] = curr;
	getCombination(r, target, curr + 1);
	back--;
	r.c -= macroList[curr].c;
	r.f -= macroList[curr].f;
	r.p -= macroList[curr].p;

	// or dont add curr 
	getCombination(r, target, curr + 1);

}

int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		cin >> Size;
		macroList = new macro[Size];
		result = new int *[Size];
		sizeMin = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			sizeMin[i] = -1;
			cin >> macroList[i].c;
			cin >> macroList[i].f;
			cin >> macroList[i].p;
		}

		int t;
		cin >> t;
		targets = new macro[t];
		for (int i = 0; i < t; i++)
		{
			cin >> targets[i].c;
			cin >> targets[i].f;
			cin >> targets[i].p;
		}

		for (int i = 0; i < t; i++)
		{
			minSize = 1e9;
			macro temp;
			temp.c = 0;
			temp.f = 0;
			temp.p = 0;
			getCombination(temp, i, 0);
		}

		for (int i = 0; i < t; i++)
		{
			if (sizeMin[i] != -1)
			{
				cout << "Case#" << i + 1 << ": ";
				for (int j = 0; j < sizeMin[i]; j++)
				{
					cout << result[i][j] << " ";
				}

				cout << "\n";
			}
			else
			{
				cout << "Case#" << i + 1 << ": -1" << "\n";
			}
		}
	}

	return 0;
}

/*

1
5
1 2 3
4 5 6
7 8 9 
9 18 12 
5 7 9
4
5 7 9
11 13 15
12 15 18
1 1 1

Case#1: 5 
Case#2: 2 3 
Case#3: 3 5 
Case#4: -1

*/