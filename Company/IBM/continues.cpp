#include<bits/stdc++.h>
using namespace std;

int maxele(vector<int> t){
    
    int max = INT_MIN;
    for(auto i : t){
        if(i > max) max = i;
    }
    return max;
}

int  check(vector<int> table)
{
    int max = maxele(table);

    vector<int> aux(max+1,0);

    for(auto i : table){
        aux[i]++;
    }

    // check for repetion or any missing elements

    // 1245 here 3 is mising 

    // 122234 l = 6  count 2 = 3  index array = 2,2 126534

    // we will get index and repalce it by highest elements in current array
    int count = 0;
    bool onces =false;
    vector<int> indexs; //used to store indexs or lefted out indexes
    stack<int> missing; // used to sotre mising elements;
    bool started = false;
    for(auto i = 0 ; i < size(aux) ; i++)
    {   
        onces = false;
         if(aux[i] == 0 && started){
            // missing elements 
            missing.push(i);
        } 

        while(!aux[i] == 0){
            if(!onces){
            started = true;
            onces = true;
            table[count] = i;
            count++;
            aux[i]--;
            }
           else
           {
            indexs.push_back(i);
            aux[i]--;
        }
      }
     
    }

    // now table is sorted
   for(auto i : table) cout<<i<<" ";
   cout<<'\n';
   for(auto i : indexs) cout<<i<<" ";

   int result = 0;
   //  replace duplicated elements 
   if(size(indexs) > 0)
   {
      // duplicated is present
      // repace duplicaed with max + 1
      
      for(auto i : indexs)
      {
        onces = false;
        for(auto j = 0 ; j < size(table) ; j++){
            
            if(i == table[j] && !onces){
                result++;
                onces = true;
                table[j] = max+1;
                max = max + 1;
            }
        }
      }     
   }

   // if missing elements
   if(size(missing) > 0){
      
      while(!missing.empty()){
        int curr = missing.top();
        missing.pop();
        for(auto j = 0 ; j < size(table) ; j++){
            if(table[j] == max)
            {   
                table[j] = curr;
            }
        }
        cout<<max<<'\n';
        max = maxele(table);
      }
    

   }
  
   cout<<'\n';
   for(auto i : table) cout<<i<<" ";

   return result;
} 

int main (){
    vector<int> table = {2,102,101,100,99,98};

    // first we will check is table sorted or not 
    // get max element 

    cout << check(table);

    

}