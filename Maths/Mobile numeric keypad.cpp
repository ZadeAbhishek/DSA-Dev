// gfg https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		long long int result;
		
		vector<vector<int>> combination = {{0,8},{1,4,2},{2,1,3,5},{3,2,6},{4,1,7,5},{5,2,4,6,8},{6,3,9,5},{7,4,8},{8,5,0,7,9},{9,6,8}};
	    
	    vector<vector<long long int>> sums(N+1,vector<long long int>(10,0));
	    
	    for(int i = 1 ; i <= N ; i++){
	        for(int j = 0 ; j <= 9 ; j++){
	           if(i == 1){
	               sums[i][j] = 1;
	           }
	           else{
	               
	               for(int prev : combination[j]){
	                   sums[i][j] += sums[i-1][prev];
	               }
	           }
	        }
	    }
	    
	    result = accumulate(sums[N].begin(),sums[N].end(),0);
	    
	    return result;
		    
		}


};