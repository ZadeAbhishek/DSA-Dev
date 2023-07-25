//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*

2
2
2 2
2
1 3 3

op
2 1
3 2

*/
class Solution
{
	public:
		vector<int> findTwoElement(vector<int> arr, int n)
		{
			// code here

			int missing;
			int repeast;
			bool oneFlag = true;
			for (auto x: arr)
				if (x == 1) oneFlag = false;
			if (oneFlag) missing = 1;
             

            // get repating number mark visited as negative 
			for (int i = 0; i < n; i++)
			{
				if (arr[(abs(arr[i]) - 1)] > 0)
				{
					arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
				}
				else repeast = abs(arr[i]);
			}

			bool r = false;
            
            // since we mark negative ifwe found postive that is missing in first place
			for (int i = 0; i < n; i++)
			{
				if (arr[i] > 0) missing = i + 1;
			}

			return { 	repeast, missing
			};

		}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		Solution ob;
		auto ans = ob.findTwoElement(a, n);
		cout << ans[0] << " " << ans[1] << "\n";
	}

	return 0;
}