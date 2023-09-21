/*
https://www.careercup.com/question?id=5680648437104640

You are given an old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on dialpad.

But as phone is old, some of the numbers and some operations can't be touched.
For eg. 2,3,5,9 keys are not responding, i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number

Calculator have 1-9 and +,-,*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.

You have to find minimum number to touches required to obtain a number.

#Input:#
There will be multiple Test cases .Each test case will consist of 4 lines
1) First line will consist of N,M,O
	N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
	M:types of operations supported (+,-,*,/)
	O: Max no of touches allowed
2) second line of input contains the digits that are working e.g 0,2,3,4,6.
3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
4) fourth line contains the number that we want to make .

#Output:#
Output contains 1 line printing the number of touches required to make the number

#Sample Test Case:#
5 
5 3 5
1 2 4 6 0
1 2 3
5
6 4 5 
1 2 4 6 9 8
1 2 3 4
91
6 2 4
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981
6 3 5
1 4 6 7 8 9
1 2 3
18

#Output:#
4
2 
5
9
2

If you have to type 18-> 2 operations. (Each touch is considered an operation),br > If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
*/

/*

Intution and flow 

either we nned to calcuate the number or we will get throught concatinate
i.e for 22 we can type 2 time '2' or we can calucate but min touch is 2 
or another example is if target is 5  and if key is available return it or calucate it

so basically we are backtraking between calcualting and concatinating

flow
imagine phone
see Screen --> check if equal to target -->  if return --> no type something -->> check on screen----


*/


#include<iostream>
using namespace std;

int Empty = -1e9;

// global variable
int touchCount = 1e9; // set to max
int *numbers;  // pointer to available numbers
int *operators;  // pointer to available operators
int target;
int touches;
int m,n,o;

// min function
int min(int x, int y){
	return (x>y)?y:x;
}

int abs(int x){
	return (x<0)?-1*x:x;
}

// calucate function
int calculate(int screen, int typed, int oper){
	
	if(screen == Empty) return typed;

	if(oper == 1) return (screen + typed);

	if(oper == 2) return (screen - typed);

	if(oper == 3) return (screen * typed);

	if(oper == 4){
		
		if(typed == 0) return -1;
		
		else return (screen / typed);

	}
}


// equal function when equal is pressed calucate  
int equal(int screen , int typed, int oper){

	// check if 0 is typed and divide is operator then return false
	if(typed == 0 && oper == 4) return false;

	else{
		int getvalue = equal(screen,typed,oper);
		return (getvalue == target)?1:0;
	}
}


void calculator(int screen, int typed, int oper, int currTouch){
	
	
	// check screen and if something is typed then calcuate value
	if(screen != Empty && typed != Empty){
		if(equal(screen,typed,oper,oper)){
            if(currTouch < touches) touchCount = min(touchCount,currTouch+1); 
		}
	}

	// check if anything is on screen and can be equal to target
	if(screen != Empty && typed == Empty && oper != -1){
        if(screen == target){
			touchCount = min(touchCount,currTouch);
		}
	}

   // check if there nothing on screen and sonething is typed
   if(screen == Empty && typed != Empty && oper != -1){
	   if(typed == target){
		  touchCount = min(touchCount,currTouch);
	   }
   }

   // check total touch count
   if(currTouch > touches) return;


   // there is some valu on screen and typed get value and move to nect operator
   for(int i = 0 ; i < m ; i++){
	 if(typed == Empty) break;
	 
	 if(typed == 0 && oper == 4) continue;

	 int getValue = equal(screen,typed,oper);

	 calculator(getValue,Empty,operators[i],currTouch+1);
   }

   // concatinate

   for(int i = 0 ; i < n ; i++){
	
	if(typed == Empty){
        calculator(screen,numbers[i],oper,currTouch+1);
	}
	else{
          int curr = abs(typed);
		  int val = curr*10 + numbers[i];
		  if(typed < 0) val = val * -1;
          calculator(val,Empty,oper,currTouch+1);
	}
   }  
}


int main(){
	int totalCase;
	cin>>totalCase;
	while(totalCase--){
		touchCount = 1e9;
		cin>>n>>m>>o;
		touches = o;
		numbers = new int[n];
		operators = new int[m];
		for(int i = 0 ; i < n ; i++) cin>>numbers[i];
		for(int i = 0 ; i < m ; i++) cin>>operators[i];
		cin>>target;
		calculator(Empty,Empty,-1,0);
		cout<<touchCount;
	} 
}


/*
1
4 2 0
1 2 4 6
1 3
0

*/