/*
https://www.careercup.com/question?id=5166688897073152
http://forums.codeguru.com/showthread.php?560529-Core-Java-programming
https://codereview.stackexchange.com/questions/136165/the-thirsty-crow
*/

/*
There are N pots. Every pots has some water in it. They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required 
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

Array of overflow no--. {1,...,On}

Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
*/
#include <iostream>
using namespace std;

// asuming we cannot use stl

void merge(int *arr, int start, int mid, int end)
{
	int leftsize = mid - start + 1;
	int rightsize = end - mid;
	int leftSide[leftsize];
	int rightSide[rightsize];
	for (int i = 0; i < leftsize; i++) leftSide[i] = arr[start + i];
	for (int i = 0; i < rightsize; i++) rightSide[i] = arr[mid + i + 1];
	int i = 0, j = 0;
	int k = start;
	while (i < leftsize && j < rightsize)
	{
		if (leftSide[i] <= rightSide[j]) arr[k] = leftSide[i], k++, i++;
		else arr[k] = rightSide[j], k++, j++;
	}

	if (i < leftsize)
	{
		arr[k] = leftSide[i], k++, i++;
	}

	if (j < rightsize)
	{
		arr[k] = rightSide[j], k++, j++;
	}
}

void mergeSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

// multiply min with remaing cntainer till k
int getstones(int *overflow_numbers, int k, int n)
{
	int total_stones = 0;

	for (int i = n - 1; i > 0; i--)
	{
		overflow_numbers[i] = max(0, overflow_numbers[i] - overflow_numbers[i - 1]);
	}

	// multiply min with remaing cntainer till k
	for (int i = 0; i < k; i++)
	{
		total_stones += (overflow_numbers[i] *(n - i));
	}

	return total_stones;
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	mergeSort(arr, 0, size - 1);
	int k;
	cin >> k;
	cout << getstones(arr, k, size) << "\n";
}

/*
test case

6
2 6 3 9 4 5
1

5
5 8 10 15 17
3

*/