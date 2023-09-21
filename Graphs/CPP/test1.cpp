// Online C++ compiler to run C++ program online
#include <iostream>

#include<vector>

using namespace std;
int main() {
  int count = 0;
  int i;
  cin >> i;
  int j = 0;
  vector < int > arr;
  while (j != i) {
    int x;
    cin >> x;
    arr.push_back(x);
    j++;
  }
  for (auto k = 0; k < i; k++) {
    int t = arr[k];
    int bo = false;
    for (auto m = 1; m <= t; m++) {
      for (auto n = 1; n <= t; n++) {
        // cout<<"m:"<<m<<" "<<"n:"<<n<<endl;
        if (m == n) {
          continue;
        }
        if (!bo) {
          if (((m & n) == 0) && ((m ^ n) == t)) {
            bo = true;
            count++;
          }
        }

      }
    }
    bo = false;
  }
  cout << count;
  return count;
}