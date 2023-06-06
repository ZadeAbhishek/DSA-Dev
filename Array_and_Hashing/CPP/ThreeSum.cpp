#include<bits/stdc++.h> 
using namespace std;
vector<vector<int>> combination(vector<int>arr, int n, int K,vector<vector<int>> &result,vector<int> temp,int sum,vector<bool> memo){
	   if(sum == K && result.size() < 1) {
		   if(temp.size() >= 3){
		   result.push_back(temp);
		   }
		   return result;
	   }

	   if(sum > K) return result;

	   for(auto index = 0 ; index < n ; index++){
		   if(memo[index] == false){
		   memo[index] = true;
		   temp.push_back(arr[index]);
		   sum += arr[index];
		   combination(arr,n,K,result,temp,sum,memo);
		   sum -= arr[index];
		   temp.pop_back();
		   memo[index] = false;
		   }
	   }

	   return result;
} 

vector<vector<int>> powerSet(vector<int> &arr, vector<int> temp, vector<vector<int>> &result){
    int n = arr.size();
    
    for(auto i = 0 ; i < pow(2,n) - 1 ; i++){
        temp.clear();
        for(auto j = 0 ; j < n ; j++){
            if(i & (1<<j)) temp.push_back(arr[j]);
        }
        result.push_back(temp);
    }
    return result;
}


vector<vector<int>> combination(vector<int>arr, int n, int K,vector<vector<int>> &result,vector<int> temp,int sum,vector<bool> memo,int curr){
       
      // cout<<sum<<" "<<curr<<endl;
       if(curr > n) return result;

       if(result.size() == 1) return result;

       if(sum == K && temp.size() == 3) {
        result.push_back(temp);
        return result;
       }   
       
       if(temp.size() > 3) return result;

       if(sum > K) return result;
       // ittertaor
       temp.push_back(arr[curr]);
       sum += arr[curr];
       combination(arr,n,K,result,temp,sum,memo,curr+1);
       sum -= arr[curr];
       temp.pop_back();
       combination(arr,n,K,result,temp,sum,memo,curr+1);
       return result; 
} 


vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	// classic examole of reccursion and subsets or combination

	vector<vector<int>> result;
    vector<vector<int>> Final;
	vector<int> temp;
    powerSet(arr,temp,result);  // 2^N * N
    for(auto i = 0 ; i < result.size() ; i++){
        //cout<<result[i].size()<<endl;
        if(result[i].size()!=3) continue;
        
        //cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
        if(result[i][0]+result[i][1]+result[i][2] == K) Final.push_back(result[i]);
    }
    if(Final.size() <= 0) {
        Final.push_back({-1});
        return Final;
        }
    set<vector<int>> Set;
    for(auto x : Final) {
        sort(x.begin(),x.end());  // N*log(N)
        Set.insert(x);
    }
    Final.clear();
    for(auto x : Set) Final.push_back(x); 
	return Final; 

}

// TC O(N*2^N)
// SC O(N)

// 9
// 2 -95 9 1 -79 88 96 0 5 
// 10

int main(){
   vector<int> arr = {1, 2 ,3 ,1 ,2 ,3 };
   int n = 6;
   int k = 6;
   vector<vector<int>> result = findTriplets(arr,n,k);
   for(auto k : result){
    for(auto x : k){
        cout<<x<<" ";
    }
    cout<<endl;
   }
}