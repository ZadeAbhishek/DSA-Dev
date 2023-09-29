#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */

void countSort(vector<vector<string>> arr) {
    int arr_size = arr.size();
    int half_way = arr_size/2;
    
    // idea is to use counting sort 
    // here we are using 2d array 
    // y 0,1
    // x = arr.size
    // find maximum element 
    
    // algorithm to get max
    auto i = 0;
    int max = INT_MIN;
    while(i < arr.size()){
        //cout<<arr[i][0];

        //method to convert string to int
        stringstream temp(arr[i][0]);
        int x;
        temp >> x;

        //compare
        if(x > max)
        max = x;
        i++;
    }
    
    // counting sort
    vector<string> ans[max+1];
    i = 0;
    int count = 0;
    while(i < arr.size()){
        stringstream temp(arr[i][0]);
        int y = 0;
        temp >> y;
        if(count < half_way){
        ans[y].push_back("-");
        }
        else{
        ans[y].push_back(arr[i][1]);
        }
        count++;
        i+=1;
    }
    for(auto it : ans){
        for(auto yt : it ){
            cout<<yt<<" ";
        }
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
