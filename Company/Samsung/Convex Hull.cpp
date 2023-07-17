/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and 
which encompasses all the given points.
*/
#include<bits/stdc++.h>
using namespace std;

// global varaible
int sameCount = 0; // count to keep track of same point (at the end of the loop we merge last point with frist point)

// struct to store points
struct point{
    int x;
    int y;
};

// function to get the orientation of points
// 0 --> represents points are 180 deg aligned
// 1 --> represents point lies in clockwise direction or we can say right to curr point
// 2 --> represents point lies in counterClockwise direction or we can say left to curr point
int orientation(point p, point q, point r){
      
      // mother Promise rattaa mar ye bhai donnt think ratta mar
      int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

      if(val == 0) return 0; // straight orientation
      
      return (val > 0)?1:2; // if val > 0 left or counterClockWise oritentation else right or clockwise orientation
}


bool comparator(point &a, point &b){
    // if two point are equal get the count
    if(a.x == b.x && a.y == b.y) sameCount++;

    if(a.x == b.x) return (a.y < b.y);
    else return (a.x < b.x);
}

// function of unqiue eleents
bool uniqueFunction(point &a, point &b){
    return (a.x == b.x && a.y == b.y);
}


// n = size of points
void convexHull(point *points , int n){
   
   sameCount = 0;

   // atleast two points are needed
   if(n < 3){
    cout<<"-1";
    return;
   }

   vector<point> hull;  // final points are searching in convex

   int leftMost = 0;
   // find left most point or starting point
   for(int i = 0 ; i < n ; i++){
    if(points[i].x < points[leftMost].x) leftMost = i;
   }

   int currPoint = leftMost, nextPoint;
   
   // loop through all point and check all point
   do{

    // push current point in hull
    hull.push_back(points[currPoint]);

    // we ding mode so that we donnt got out of bound see while condition
    nextPoint = (currPoint + 1)%n; 

    for(int i = 0; i < n; i++){

        // check orietation we want right and counter clockwise only orientation
        if(orientation(points[currPoint],points[i],points[nextPoint]) == 2){
            nextPoint = i;
        } 

    }
    currPoint = nextPoint;    
   
   
   }while(currPoint != leftMost);


   // sort the hulls
   sort(hull.begin(),hull.end(),comparator);

   // remove all duplicate elements and get count last count of non duplicate elements
   // return pointer to last elments
   auto end = unique(hull.begin(),hull.end(),uniqueFunction); 

   hull.resize(std::distance(hull.begin(),end));

   
   // if hull size() < 3 only two point is present return
   if(n < 3 && sameCount > 0 || hull.size() < 3){
    cout<<"-1";
    return;
   }
   else{
     for (int i = 0; i < hull.size(); i++){
            if(i != hull.size() - 1) // just to print in nite form
                cout << hull[i].x << " " << hull[i].y << ", ";
            else
                cout << hull[i].x << " " << hull[i].y; 
        }       
   }
   return;
}

// driver function
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int totalPoints;
        cin>>totalPoints;
        point * points = new point[totalPoints];

        for(int i = 0 ; i < totalPoints ; i++){
            cin>>points[i].x>>points[i].y;
        }

        convexHull(points,totalPoints);

        cout<<"\n";
    }
}

/*
test case
i/p
1
7
0 3 
2 2 
1 1 
2 1
3 0 
0 0 
3 3


o/p
0 0, 0 3, 3 0, 3 3

*/