/*Find sum of all prime from 1 to n TC(nlogn) SC(n)*/
/*Sieve of Eratosthenes */

// https://www.youtube.com/watch?v=dyrRM8dTEus&ab_channel=AnujBhaiya
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

long long int getPrime(int n)
{
	bool buffer[n + 1];
	memset(buffer, true, n + 1);

	buffer[1] = false;

	for (int i = 2; (i*i) <= n; i++)
	{
		for (int j = (2 *i); j <= n; j += i)
		{
			buffer[j] = false;
		}
	}

	long long int res = 0;

	for (int i = 1; i < n + 1; i++)
	{
		if (buffer[i]) res += i;
	}

	return res;

}

int main()
{
	int n;
	cin >> n;
	cout << getPrime(n) << "\n";
}