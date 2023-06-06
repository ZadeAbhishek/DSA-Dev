int cutRode(vector<int> &price, int n, int len, int sum, int &final){
  //cout<<(len==n)<<" "<<sum<<"\n";
  if(len > n) return final;
  
  if (len == n) {
    final = max(sum, final);
    return final;
  }

  for(auto i = 0 ; i < n ; i++){
	  sum += price[i];
	  len += (i + 1);
	  cutRode(price,n,len,sum,final);
	  len -= (i+1);
	  sum -= price[i]; 
  }
  return final;
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int final = INT_MIN;
	int f = cutRode(price,n,0,0,final);
	return f;

}


// input
// 2
// 5
// 42 68 35 1 70 
// 8
// 25 79 59 63 65 6 46 82 

// Output
// 210
// 316