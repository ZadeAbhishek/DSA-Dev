#include<bits/stdc++.h>
using namespace std;

int minOperation = 1e9;

// greedy approch reducce target as much as possible 

 int brokenCalc(int startValue, int target) {
        
        if(startValue >= target) return startValue - target;

        if(target%2 == 0) return 1 + brokenCalc(startValue,target/2);

        else return 1 + brokenCalc(startValue,target+1);
    }
 

    int brokenCalc_iterative(int &startValue, int &target) {
        
		// res for counting number of operation
        int res = 0;
        
        while(target > startValue)
        {
			// if target is odd we will make it even
            if(target % 2)
                ++target;
			// if target is even divide by 2
            else
                target /= 2;
            
            ++res;
        }
        return res  + startValue - target;
    }



int main(){
    brokenCalc(2,3);
    cout<<minOperation<<"\n";
}