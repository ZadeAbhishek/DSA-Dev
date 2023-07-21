/*
https://www.geeksforgeeks.org/samsung-interview-experience-on-campus-for-r-d-noida/
https://www.youtube.com/watch?v=Kc43BLd3JJM&ab_channel=AnuragCodes

A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum 
number of rows having all 1’s.

for eg, n=3, m=3,
            1 0 0

            1 0 1

            1 0 0

if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so 
answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there 
is 1 row with all 1’s.
*/

//  I am not confirm if hashmaps is been used or not
#include <bits/stdc++.h>
using namespace std;

// structure to store coloum wise string and zero count for each string
struct column
{
	string coloum = "";
	int zeros_count = 0;
};

// convet matrix into string and store it in col struct with counting zero
void convert(column *col, int *matrix, int &coloum_size, int &row_size)
{
	int index = -1;
	for (int i = 0; i < coloum_size * row_size; i++)
	{
		if (i % row_size == 0) index++;

		if (matrix[i] == 1)
		{
			col[index].coloum += '1';
		}

		if (matrix[i] == 0)
		{
			col[index].coloum += '0';
			col[index].zeros_count++;
		}
	}

	return;
}

// calucuate toggle col
// store them them in each hashmap 
// if we can toggle the zeros of coloum then inr count
// calcuate max same colums that we can toggle
// return it
int toggle_count(column *col, int k, int &col_size)
{
	int result = 0;
	unordered_map<string, int> table;
	for (int i = 0; i < col_size; i++)
	{
		if (table.count(col[i].coloum))
		{
			if (table[col[i].coloum] > 0) table[col[i].coloum]++;
		}
		else
		{
			if (col[i].zeros_count <= k && ((k - col[i].zeros_count) % 2 == 0)) table.insert({ col[i].coloum, 1 });
			else table.insert({ col[i].coloum, 0 });
		}
	}

	for (auto c: table) result = max(result, c.second);

	return result;
}

int main()
{
	int totalTestCase;
	cin >> totalTestCase;
	int colum_size;
	int row_size;
	int k;
	for (int t = 0; t < totalTestCase; t++)
	{
		cin >> colum_size >> row_size;
		cin >> k;
		int *matrix = new int[row_size *colum_size];
		for (int i = 0; i < row_size * colum_size; i++)
		{
			cin >> matrix[i];
		}

		column cols[colum_size];
		convert(cols, matrix, colum_size, row_size);
		cout << (t + 1) << ":" << toggle_count(cols, k, colum_size) << "\n";
	}

	return 0;
}

/*

5
3 3
2
1 0 1
1 0 0
1 0 1
3 3
1
1 0 1
1 0 0
1 0 1
4 3
1
1 0 0
1 0 0
1 0 0
1 0 0
4 3
1
1 0 1
1 0 0
1 0 0
1 0 0
4 3
2
1 0 0
1 0 0
1 0 0
1 0 0

o/p
1
2
0
1
4
*/