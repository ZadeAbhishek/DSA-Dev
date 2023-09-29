// this is greedy approch

#include <bits/stdc++.h>
using namespace std;

vector<vector < int>> merge(vector<vector < int>> &intervals)
{
	// sort intervals according to start times
	sort(intervals.begin(), intervals.end());

	//result
	vector<vector < int>> result;

	//add start element to result;
	result.push_back(intervals[0]);

	//check intervals
	for (auto &interval: intervals)
	{
		if (result.back()[1] >= interval[0]) result.back()[1] = max(result.back()[1], interval[1]);
		else result.push_back(interval);
	}

	return result;
}

int main() {}

/**
 *Input: intervals =[[1,3], [2,6], [8,10], [15,18]]
 *Output:[[1,6], [8,10], [15,18]]
 *Explanation: Since intervals[1,3] and[2,6] overlap, merge them into[1,6].
 */