class Solution {
public:
int a[10000] = { 0 };
    int fib(int n){
        if(n == 0 || n == 1) return n;
        if(a[n]) return a[n];
        return a[n] = fib(n - 1) + fib(n - 2); 
    }
};