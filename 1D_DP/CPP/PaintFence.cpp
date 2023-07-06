// Paint Fence algorithm
// DO revision 
// https://www.youtube.com/watch?v=5eFh5CC-8KY&t=504s&ab_channel=CodeHelp-byBabbar
#include<iostream>
#include<cstring>


#define mod 1000000007

// recusrive solution 
int paintFence(int n , int k){
    // base case
    if(n == 1) return k; // we have only one fence so we can use on one color return k;
    if(n == 2) return k + (k * (k-1)); // no of fences having same paint k since we can pain any two color
                                       // no of haiving two diff color k * k-1 == 3*3-1 == 3*2
    
    int same = ((k-1)*paintFence(n-2,k)); // k-1 color * last (n-1) diff i.e (n-2) total will give curr same 
    int diff = ((k-1)*paintFence(n-1,k)); // k-1 color * last (n-1) total
    return  same + diff;                                    
}

// Dp + recursive
int paintFenceDP(int n , int k, int *memo){
    // base case
    if(n == 1) return k; // we have only one fence so we can use on one color return k;
    if(n == 2) return k + (k * (k-1)); // no of fences having same paint k since we can pain any two color
                                       // no of haiving two diff color k * k-1 == 3*3-1 == 3*2
    if(memo[n] != -1) return memo[n];
    int same = ((k-1)*paintFenceDP(n-2,k,memo)); // k-1 color * last (n-1) diff i.e (n-2) total will give curr same 
    int diff = ((k-1)*paintFenceDP(n-1,k,memo)); // k-1 color * last (n-1) total
    return  memo[n] = same + diff;                                    
}

//Tabulation method
int paintFenceTab(int n , int k, int *memo){
    memo[1] = k;
    memo[2] = k + (k*(k-1));

    for(auto i = 3 ; i <= n ; i++){
        memo[i] = ((k-1)*memo[i-2]) + ((k-1)*memo[i-1]);
    }
    return memo[n];
}

//Using Mod 10^7 for biiger calculation
int add(int x, int y){
    return (x%mod + y%mod)%mod;
}

int mul(int x, int y){
    return ((x%mod) * (y%mod))%mod;
}

int paintFenceDPMod(int n , int k, int *memo){
    // base case
    if(n == 1) return k; // we have only one fence so we can use on one color return k;
    if(n == 2) return add(k,mul(k,k-1)); // no of fences having same paint k since we can pain any two color
                                       // no of haiving two diff color k * k-1 == 3*3-1 == 3*2
    if(memo[n] != -1) return memo[n];
    int same =  mul(k-1,paintFenceDPMod(n-2,k,memo)); // k-1 color * last (n-1) diff i.e (n-2) total will give curr same 
    int diff =  mul(k-1,paintFenceDPMod(n-1,k,memo));; // k-1 color * last (n-1) total
    return  memo[n] = add(same,diff);                                    
}




int main(){
    int n = 4; // No of Fences to be paintined 
    int k = 3; // No of Paint we have in option
    std::cout<<paintFence(n,k)<<"\n";
    int memo[n+1]; // 1 indexed
    std::memset(memo,-1,sizeof memo); // It is defined in <cstring> header file.
    std::cout<<paintFenceDP(n,k,memo)<<"\n";
    int memo2[n+1]; // 1 indexed
    std::memset(memo2,0,sizeof memo2); // It is defined in <cstring> header file.
    std::cout<<paintFenceTab(n,k,memo2)<<"\n";
    int memo3[n+1]; // 1 indexed
    std::memset(memo3,-1,sizeof memo3); // It is defined in <cstring> header file.
    std::cout<<paintFenceDPMod(n,k,memo3)<<"\n";
}