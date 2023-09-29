#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> result)
{
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int partion(vector<int> &arr, int pivot, int i, int j)
{

    while (i <= j)
    {
        // cout<<arr[i]<<" "<<arr[j]<<" "<<pivot<<"\n";
        if ((arr[i] >= arr[pivot]) && (arr[j] <= arr[pivot]))
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if (arr[i] < arr[pivot])
        {
            i++;
        }
        if (arr[j] > arr[pivot])
        {
            j--;
        }
    }
    swap(arr[pivot], arr[j]);
    return j;
}
class Solution
{
private:
    void sort(vector<int> &arr, int i, int j)
    {
        // take a pivot send to partition
        //cout << i << " " << j << "\n";
        if (i > j)
        {
            return;
        }
        int p = partion(arr, i, i + 1, j);
        printVector(arr);
        sort(arr, i, p - 1);
        sort(arr, p + 1, j);
        return;
    }

public:
    void QuickSort(vector<int> &arr)
    {
        sort(arr, 0, arr.size() - 1);
        return;
    }
};

int main()
{
    vector<int> List = {7, 11, 9, 3, 6, 10, 66, 78, 96, 12, 36, 105, 700, 64, 3, 6, 0, -1};
    int len = List.size();
    for (int i = 0; i < len; i++)
    {
        cout << List[i] << " ";
    }
    cout << "\n";
    Solution *solve = new Solution();
    solve->QuickSort(List);
    for (int i = 0; i < List.size(); i++)
    {
        cout << List[i] << " ";
    }
}