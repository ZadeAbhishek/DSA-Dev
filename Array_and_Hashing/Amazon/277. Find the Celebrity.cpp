// C++ program to find celebrity using
// stack data structure
#include <bits/stdc++.h>
using namespace std;
//##stack
// knows function check if a knows b
bool knows(int a, int b, vector<vector<int> >& matrix)
{
    return matrix[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int> >& matrix)
{

    stack<int> s;
    // Celebrity
    int C;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B, matrix)) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C)
            && (knows(C, i, matrix)
                || !knows(i, C, matrix)))
            return -1;
    }

    return C;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };

    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}