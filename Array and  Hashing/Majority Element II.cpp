class Solution {
public:
    
     vector<int> merge(vector<int> &x,vector<int> &y){
            int len1 = x.size();
            int len2 = y.size();
            vector<int> result;
            int i,j;
            i = j = 0;
            while(i < len1 && j < len2){
                if(x[i] < y[j]){
                    result.push_back(x[i]);
                    i++;
                }
                else{
                    result.push_back(y[j]);
                    j++;
                }
            }
            while(i < len1){
                result.push_back(x[i]);
                i++;
            }
              while(j < len2){
                result.push_back(y[j]);
                j++;
            }
            return result;
    }

     vector<int> sort(vector<int> &arr, int low , int high){
        vector<int> result;
            if(low == high){
              result.push_back(arr[low]);
              return result;
            }
            int mid = (low + high) / 2 ;
            vector<int> x = sort(arr,low,mid);
            vector<int> y = sort(arr,mid+1,high);
            result = merge(x,y);
    
        return result;
 }
    
    
    vector<int> majorityElement(vector<int>& nums) {
        
    
       // some how i need sort this array asumming unsorted 
        
       vector<int> sorted = sort(nums,0,size(nums)-1);
        
       vector<int> temp; 
        
       // used N/3 as triger 
        
       int count = 1;
       
       int prev  = sorted[0]; 
        
       if(count > size(sorted)/3) temp.push_back(sorted[0]); 
        
       for(auto i = 1; i < size(sorted); i++)
       {
           if(sorted[i] == sorted[i-1]) count++;
           
           else count = 1;
           
           if(count == size(sorted)/3 + 1) {
               
               temp.push_back(sorted[i]);
       } 
    
    }
        
        return temp;
    }
    
};
