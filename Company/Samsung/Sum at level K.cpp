/*
Given a level K , you have to find out the sum of data of all the nodes at level K in a binary tree.
Input is given as:
(P(C()())(C()())) P is for Parent, C is for child. 
if parent has one child : (P(C()())()) 
if parent has no child : (P()())

sample test Case
1
3 
(0(5(6()())(-4()(9()())))(7(1()())(3()())))

op 9


1
2
(0(1(3()())(4()()))(2(5()())(10()())))

op 22

*/

#include<iostream>
#include<string>
using namespace std;


// global variables
string tree; 
int sum_of_level;

// buffer to remaimber the sum at each level
int buffer[100]; // at max there will be 100 height of tree

// function to get sum
int getSum(){
	int currLevel = 0,number = 0; // to track level and number from string
	int commit = 0,negative = 0;

	for(auto s : tree){

		if(s == '(' || s == ')'){
			// check we habe any number to add from previous level
			if(commit){
				number = negative?-1*number:number;
				negative = 0;
			}
			buffer[currLevel] += number;
			number = 0;
			commit = 0;
			if(s == '(') currLevel++;
			else if(s == ')') currLevel--;
		}
        
		// check for negative no.
		else if(s == '-') negative = 1, commit = 1;
		else{
			number = (number * 10) + s - '0';
			commit = 1;
		}

	}

	return buffer[sum_of_level+1];
}


int main(){
	int testcase;
	cin>>testcase;
	while(testcase--){
		cin>>sum_of_level>>tree;
		cout<<getSum()<<endl;
	}
	return 0;
}