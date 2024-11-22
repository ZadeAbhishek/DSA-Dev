#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> processQueriesOnCart(vector<int>& items, const vector<int>& query) {
    // Process each query
    for (int q : query) {
        if (q > 0) {
            // Add item to the end of the cart
            items.push_back(q);
        } else {
            // Remove the first occurrence of the absolute value of `q`
            int itemToRemove = -q;
            auto it = find(items.begin(), items.end(), itemToRemove);
            if (it != items.end()) {
                items.erase(it);
            }
        }
    }

    // Return the final state of the cart
    return items;
}


vector<int> processQueriesOnCartOptimised(vector<int>& items, const vector<int>& query) {
    
    unordered_map<int,queue<int>> hash; // we call it as hash number , indexs of appering
    for(auto i = 0 ; i < items.size(); i++){
        // create hash
        if(hash.count(items[i])){ hash[items[i]].push(i);}
        else {
            queue<int> temp;
            temp.push(i);
            hash.insert({items[i],temp});
        }
    }
    // Iterate over all querys iteam and check if we want to add or delete
    for(auto q : query){
        if(q > 0){
            // add to hash
            items.push_back(q);
            int lastElement = items.size()-1;
            if(hash.count(q)){hash[q].push(lastElement);}
            else { 
               queue<int> temp;
               temp.push(lastElement); 
               hash.insert({items[q],temp});
            }
        }
        else {
            int eliminate = -q;
            if(hash.count(eliminate)){
                int getIndex = hash[eliminate].front();
                hash[eliminate].pop();
                items[getIndex] = -1;
            }
        }

        // Once we have done -1
        // remove all -1  and send it
    }
    vector<int> result;
        for(auto x : items){
            if(x > 0) result.push_back(x);
        }


    // Return the final state of the cart
    return result;
}

// Driver code to test the function
int main() {
    vector<int> items = {1, 2, 1, 2, 1};
    vector<int> query = {-1, -1, 3, 4, -3};

    vector<int> result = processQueriesOnCartOptimised(items, query);

    // Output the final cart
    cout << "Final Cart: ";
    for (int item : result) {
        cout << item << " ";
    }
    cout << endl;  // Expected output: 2 2 1 4

    return 0;
}