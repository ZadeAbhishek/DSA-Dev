/*Write a program to allocate a 3D-array dynamically. */ 
#include <iostream>
using namespace std;

void single_pointer_method()
{
	int x, y, z;
	cin >> x >> y >> z;
	int *matrix = new int[x *y *z];
	int count = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{ 	*(matrix + i *y *z + j *z + k) = ++count;
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				cout << *(matrix + i *y *z + j *z + k) << " ";
			}

			cout << endl;
		}

		cout << endl;
	}

	// dealocate
	delete[] matrix;
}

void triple_pointer_method()
{
	int x, y, z;
	cin >> x >> y >> z;
	int count = 0;
	int ***matrix = new int **[x];

	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int *[y];
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = new int[z];
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				matrix[i][j][k] = ++count;
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				cout << matrix[i][j][k] << " ";
			}

			cout << "\n";
		}

		cout << "\n";
	}
    delete[] matrix;
}

int main()
{
	// single_pointer_method();
	triple_pointer_method();
}