/*** Aggrisive cows
 * 
 * step 1 -> If stall are not sorted sort them
 * step 2 -> get range start = 0 end = maxelement - minelement
 * step 3 -> calculate mid
 * step 4 -> place cows accrding to min distance of mid and check if we can palce all if yes return treu or retren false
 * step 5 -> if return true from step 4 Anw = mid and start is mid + 1 else if fasle end = mid - 1
 * step6  -> if start < end repeat step 3 else return answer; 
 * 
*/
#include<bits/stdc++.h>

bool check_cow_placement(std::vector<int> &stalls, int k, int mid){
    int maxi = 0;
    int cow = 1;
    int lastCowPos = stalls[0];

    for(int i = 1 ; i < stalls.size() ; i++){
        if(stalls[i] - lastCowPos >= mid) {
            lastCowPos = stalls[i]; 
            cow++;
            if(cow == k) return true;
    }
    }

    return false;
}


int can_We_Place_Cows(std::vector<int> &stalls, int k){
     std::sort(stalls.begin(),stalls.end());
     int start = 0;
     int maxi = *max_element(stalls.begin(),stalls.end()); // we  optimise this step
     int mini = *min_element(stalls.begin(),stalls.end()); // we can optimised this step
     int end = maxi - mini;
     int ans = -1;
     int mid;
     while(start <= end){
        mid = (start + end)/2;
        if(check_cow_placement(stalls,k,mid)){
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
     }
     return ans;

}


int main() {
    std::vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;
    int result = can_We_Place_Cows(stalls, k);
    if (result != -1) {
        std::cout << "Maximum minimum distance between cows for " << k << " cows is: " << result << std::endl;
    } else {
        std::cout << "Could not place " << k << " cows with the given stall configuration." << std::endl;
    }
    return 0;
}
