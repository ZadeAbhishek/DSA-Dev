#include <bits/stdc++.h>
#include <queue>
using namespace std;

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
float median(int d, int temp[],int pars){
     int arr[200];
     for(auto i = 0 ; i < 201 ; i++){
        arr[i] = temp[i];
     }
     int sze =d;
     int i = 0;
     d = (d/2)+1;
     int median = 0;
     int prev = 0;
     while(arr[i] < 201){
        if(arr[i] != 0){
            int j = i;
            while(arr[j] != 0 && d && pars <= 0){
                prev = median;
                arr[j]--;
                d--;
                median = j;
            }
            pars--;
        }
        i++;
     }
     if(sze%2 == 0) return (float)((float)median+ (float)prev) / 2;
     else return (float)median;   
}

int activityNotifications(vector<int> expenditure, int d) {
   int noti = 0;
   vector<int> count(201,0);
   long int i = 0;
   while(i < expenditure.size()){
    count[expenditure[i]]++;
    i++;
   }
   int j = d;
   int pars = 0;
   while(j < expenditure.size()){
    float m = median(d,count.data(),pars);
    if(expenditure[j] >= (2 * m))
    noti++;
    
    pars++;
    j++;
   }
   return noti;
}

int main()
{
   vector<int> res; 
   int size;
   int windowsSize;

   cin >> size >> windowsSize;
   
   while(size){
     int temp ;
     cin>> temp;
     res.push_back(temp);
     size--;
   }
   cout << activityNotifications(res,windowsSize);
}
