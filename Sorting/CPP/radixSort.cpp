#include<bits/stdc++.h>

using namespace std;

void printVector(vector < int > result) {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

class Solution {
    private:
        int max(vector < int > & arr) {
            int max = INT_MIN;
            for (auto i: arr) {
                if (i > max) {
                    max = i;
                }
            }
            return max;
        }

    void CountingSort(vector < int > & arr, int div, int max) {
        // step 1 map array elements to auxarr 
        // aux is of size 10 becuase in digit range 0-9 dec
        int auxarr[10] = {
            0
        };
        for (auto it: arr) {
            auxarr[(it / div) % 10]++;
        }
        // so lets say 700 her last digit is 0 therfore aux[0] will inc
        // in short this will count number of last digit

        //step 2 Make reserve places 10
        // basic if in array there are 3 ele with unit place digit as 0
        // then in according to sort in final arr stating 3 place will be required for ele with 0
        // then next index should know from how many places it will start
        for (auto it = 1; it < 10; it++) {
            auxarr[it] += auxarr[it - 1];
            // basically we are adding count of prev with count of next
            // to keep track of placese for final output
        }
        // cout<<"aux"<<"\n";
        // for(auto it = 0 ; it < 10 ; it++){
        //  cout<<auxarr[it]<<" ";
        // }
        // cout<<"\n";
        int prearr[arr.size()] = {
            0
        };

        // step 3 start traking element from aux and placing in prearr

        for (auto i = arr.size() - 1; i > 0; i--) {
            prearr[auxarr[(arr[i] / div) % 10] - 1] = arr[i];
            auxarr[(arr[i] / div) % 10]--;
        }
        prearr[auxarr[(arr[0] / div) % 10] - 1] = arr[0];
        auxarr[(arr[0] / div) % 10]--;

        for (auto i = 0; i < arr.size(); i++) {

            arr[i] = prearr[i];
        }
    }

    void sort(vector < int > & arr) {
        // so according to radix sort we have to sort according digits

        // step 1 : Find max element in arr
        int m = max(arr);
        // step 2 : We have to sort according to number of digits in max
        int count = 1;
        for (auto div = 1;
            (m / div > 0); div *= 10) {
            // for ex 700 then this loop will run 3 time 
            // 700/1 > 0 true
            // 700/10 > 0 true
            // 700/100 > 0 true
            // 700/ 100 > 0 false
            cout << "Pass:" << count << "\n";
            count++;
            // sorting is used here is counting sort
            CountingSort(arr, div, m);
            printVector(arr);
        }
    }
    public:
        void RadixSort(vector < int > & arr) {
            sort(arr);
            return;
        }
};

int main() {
    vector < int > List = {
        7,
        11,
        9,
        3,
        6,
        10,
        66,
        78,
        96,
        12,
        36,
        105,
        700,
        64,
        3,
        6,
        1023,
        106668
    };
    int len = List.size();
    for (int i = 0; i < len; i++) {
        cout << List[i] << " ";
    }
    cout << "\n";
    Solution * solve = new Solution();
    solve -> RadixSort(List);
    for (int i = 0; i < List.size(); i++) {
        cout << List[i] << " ";
    }
}