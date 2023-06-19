#include<stdio.h>


int uBST(int n, int *a){
    if(n <= 1) return 1;

    if(a[n]) return a[n];

    for(int i = 1 ; i <= n ; i++){
        a[n] += uBST(i - 1,a) * uBST(n - i,a); 
    }

    return a[n];


}

int main(){
    int n = 3;
    int dp[4] = {0 ,0 ,0, 0};
    int *a = dp;
    printf("Unique No of BST are %d",uBST(n,a));
    return 0;
}