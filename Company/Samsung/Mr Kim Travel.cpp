/*
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the 
customers and then return to his home. Each location of the office, his home, and the customers is 
given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two 
arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the 
absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the 
customers are all distinct. You should plan an optimal way to visit all the N customers and return 
to his among all the possibilities.
 
   
 
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the 
customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) 
shortest path visiting all the customers and returning to his home. Your program only have to report
the distance of a (the) shortest path. 
 
  
 
[Constraints]
 
5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.
 
  
 
[Input]
 
You are given 10 test cases. Each test case consists of two lines; the first line has N, 
the number of the customers, and the following line enumerates the locations of the office, 
Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), 
which is reprensented by ‘x y’.
 
  
 
[Output]
 
Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. 
Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are 
separated by a space.
 
  
 
[I/O Example]
 
Input (20 lines in total. In the first test case, the locations of the office and the home are 
(0, 0) and (100, 100) respectively, 
and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)
 
 
5 ← Starting test case #1
 
0 0 100 100 70 40 30 10 10 5 90 70 50 20
 
6 ← Starting test case #2
 
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
 
10 ← Starting test case #3
 
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
 
...  
 
 
  
 
Output (10 lines in total)
 
 
#1 200
 
#2 304
 
#3 366
 
test case


5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
7
22 47 72 42 61 93 8 31 72 54 0 64 26 71 93 87 84 83
8
30 20 43 14 58 5 91 51 55 87 40 91 14 55 28 80 75 24 74 63
9
3 9 100 100 16 52 18 19 35 67 42 29 47 68 59 38 68 81 80 37 94 92
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
10
26 100 72 2 71 100 29 48 74 51 27 0 58 0 35 2 43 47 50 49 44 100 66 96
10
46 25 16 6 48 82 80 21 49 34 60 25 93 90 26 96 12 100 44 69 28 15 57 63
10
94 83 72 42 43 36 59 44 52 57 34 49 65 79 14 20 41 9 0 39 100 94 53 3
10
32 79 0 0 69 58 100 31 67 67 58 66 83 22 44 24 68 3 76 85 63 87 7 86

expected op

Case #1: 200
Case #2: 304
Case #3: 265
Case #4: 307
Case #5: 306
Case #6: 366
Case #7: 256
Case #8: 399
Case #9: 343
Case #10: 391

intution behind this 
this example is classic exapmple of backtraking will try all possible combination from
office -->>     all customers homes    --> home
            [this part we are applying]
            [ back traking            ]
 
*/
#include<iostream>
using namespace std;

// global variable

// store coordinates
int x[20]; 
int y[20];
int totalCorrdinate;
int minDist = 1e9;

int min(int x , int y){
    return (x < y)?x:y;
}

int abs(int x){
   return x > 0?x:-1*x;
}

int distance(int source, int desination){
    // given in question
    return abs(abs(x[desination] - x[source]) + abs(y[desination] - y[source]));  
}

void minDistance(int prev, int *visted, int currDistance , int homes){
    // base case
    if(homes == totalCorrdinate){
        // we are leaving the office at start so n - 1
       minDist = min(minDist,currDistance + distance(prev,totalCorrdinate+1));
       return;
    }

    // main iter
    for(int i = 1 ; i <= totalCorrdinate ; i++){
        
        if(visted[i] == 0){
            visted[i] = 1;
            minDistance(i,visted,currDistance+distance(prev,i),homes+1);
            visted[i] = 0;
        }
    }

    return;
}


int main(){
    int totalTest;
    cin>>totalTest;
    while(totalTest--){
        minDist = 1e9;
        cin>>totalCorrdinate;
        int visited[totalCorrdinate+2] = {0};

        //  0 0 is home 
        // n +1  n +1 is destination

        cin>>x[totalCorrdinate+1]>>y[totalCorrdinate+1]>>x[0]>>y[0];
        for(int i = 1 ; i <= totalCorrdinate ; i++){
            cin>>x[i]>>y[i];
        }
         
        // we are starting with 0 office
        minDistance(0,visited,0,0);
        cout<<totalTest+1<<" "<<minDist<<"\n";

    }
    return 0;
}

/*
1
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20

200

*/